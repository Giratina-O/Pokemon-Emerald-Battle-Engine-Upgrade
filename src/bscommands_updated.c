#include "types.h"
#include "defines.h"
#include "battle_locations.h"
#include "battle_structs.h"
#include "vanilla_functions.h"
#include "static_resources.h"
#include "new_battle_struct.h"
#include <string.h>

void atk7D_set_rain()
{
    battlescripts_curr_instruction++;
    if (battle_weather.flags.air_current || battle_weather.flags.harsh_sun)
    {
        battlescripts_curr_instruction = (void*) 0x082D9F1C; //but it failed script
    }
    else if (battle_weather.flags.downpour || battle_weather.flags.permament_rain || battle_weather.flags.rain || battle_weather.flags.heavy_rain)
    {
        move_outcome.missed = 1;
        battle_communication_struct.multistring_chooser = 2;
    }
    else
    {
        battle_weather.flags.rain = 1;
        battle_communication_struct.multistring_chooser = 1;
        if (get_item_effect(bank_attacker, 1) == ITEM_EFFECT_DAMPROCK)
            battle_effects_duration.weather_dur = 8;
        else
            battle_effects_duration.weather_dur = 5;
    }
    return;
}

void atk95_set_sandstorm()
{
    battlescripts_curr_instruction++;
    if (battle_weather.flags.air_current || battle_weather.flags.harsh_sun || battle_weather.flags.heavy_rain)
    {
        battlescripts_curr_instruction = (void*) 0x082D9F1C; //but it failed script
    }
    else if (battle_weather.flags.sandstorm || battle_weather.flags.permament_sandstorm)
    {
        move_outcome.missed = 1;
        battle_communication_struct.multistring_chooser = 2;
    }
    else
    {
        battle_weather.flags.sandstorm = 1;
        battle_communication_struct.multistring_chooser = 3;
        if (get_item_effect(bank_attacker, 1) == ITEM_EFFECT_SMOOTHROCK)
            battle_effects_duration.weather_dur = 8;
        else
            battle_effects_duration.weather_dur = 5;
    }
    return;
}

void atkBB_set_sunny()
{
    battlescripts_curr_instruction++;
    if (battle_weather.flags.air_current || battle_weather.flags.heavy_rain)
    {
        battlescripts_curr_instruction = (void*) 0x082D9F1C; //but it failed script
    }
    else if (battle_weather.flags.sun || battle_weather.flags.permament_sun || battle_weather.flags.harsh_sun)
    {
        move_outcome.missed = 1;
        battle_communication_struct.multistring_chooser = 2;
    }
    else
    {
        battle_weather.flags.sun = 1;
        battle_communication_struct.multistring_chooser = 4;
        if (get_item_effect(bank_attacker, 1) == ITEM_EFFECT_HEATROCK)
            battle_effects_duration.weather_dur = 8;
        else
            battle_effects_duration.weather_dur = 5;
    }
    return;
}

void atkC8_set_hail()
{
    battlescripts_curr_instruction++;
    if (battle_weather.flags.air_current || battle_weather.flags.harsh_sun || battle_weather.flags.heavy_rain)
    {
        battlescripts_curr_instruction = (void*) 0x082D9F1C; //but it failed script
    }
    else if (battle_weather.flags.hail || battle_weather.flags.permament_hail)
    {
        move_outcome.missed = 1;
        battle_communication_struct.multistring_chooser = 2;
    }
    else
    {
        battle_weather.flags.hail = 1;
        battle_communication_struct.multistring_chooser = 5;
        if (get_item_effect(bank_attacker, 1) == ITEM_EFFECT_ICYROCK)
            battle_effects_duration.weather_dur = 8;
        else
            battle_effects_duration.weather_dur = 5;
    }
    return;
}

void atk7E_set_reflect()
{
    battlescripts_curr_instruction++;
    u8 side = is_bank_from_opponent_side(bank_attacker);
    if (side_affecting_halfword[side].reflect_on)
    {
        move_outcome.missed = 1;
        battle_communication_struct.multistring_chooser = 0;
    }
    else
    {
        side_affecting_halfword[side].reflect_on = 1;
        if (get_item_effect(bank_attacker, 1) == ITEM_EFFECT_LIGHTCLAY)
            side_timers[side].reflect_timer = 8;
        else
            side_timers[side].reflect_timer = 5;
        side_timers[side].reflect_bank = bank_attacker;
        if (battle_flags.double_battle && count_alive_pokes_on_side(1) == 2)
            battle_communication_struct.multistring_chooser = 2;
        else
            battle_communication_struct.multistring_chooser = 1;
    }
    return;
}

void atk92_set_lightscreen()
{
    battlescripts_curr_instruction++;
    u8 side = is_bank_from_opponent_side(bank_attacker);
    if (side_affecting_halfword[side].light_screen_on)
    {
        move_outcome.missed = 1;
        battle_communication_struct.multistring_chooser = 0;
    }
    else
    {
        side_affecting_halfword[side].light_screen_on = 1;
        if (get_item_effect(bank_attacker, 1) == ITEM_EFFECT_LIGHTCLAY)
            side_timers[side].lightscreen_timer = 8;
        else
            side_timers[side].lightscreen_timer = 5;
        side_timers[side].lightscreen_bank = bank_attacker;
        if (battle_flags.double_battle && count_alive_pokes_on_side(1) == 2)
            battle_communication_struct.multistring_chooser = 4;
        else
            battle_communication_struct.multistring_chooser = 3;
    }
    return;
}

u8 is_of_type(u8 bank, u8 type);

void atk96_weather_damage()
{
    battlescripts_curr_instruction++;
    s32 damage = 0;
    u8 ability = battle_participants[bank_attacker].ability_id;
    u8 ability_effect = has_ability_effect(bank_attacker, 0, 1);
    if (weather_abilities_effect() && !(get_item_effect(bank_attacker, 1) == ITEM_EFFECT_SAFETYGOOGLES) && !(ability_effect && ability == ABILITY_MAGIC_GUARD) &&!(hit_flags_for_banks & bits_table[bank_attacker]))
    {
        if (battle_weather.flags.sandstorm || battle_weather.flags.permament_sandstorm)
        {
            if (!(is_of_type(bank_attacker, TYPE_GROUND) && is_of_type(bank_attacker, TYPE_STEEL) && is_of_type(bank_attacker, TYPE_ROCK)) && !(ability_effect && (ability == ABILITY_SAND_FORCE || ability == ABILITY_SAND_RUSH)))
            {
                if (!(status3[bank_attacker].underground || status3[bank_attacker].underwater))
                {
                    damage = battle_participants[bank_attacker].max_hp >> 4;
                    if (damage == 0)
                        damage = 1;
                }
            }
        }
        else if (battle_weather.flags.hail || battle_weather.flags.permament_hail)
        {
            if (!(is_of_type(bank_attacker, TYPE_ICE)) && !(ability_effect && (ability == ABILITY_SNOW_CLOAK)))
            {
                if (!(status3[bank_attacker].underground || status3[bank_attacker].underwater))
                {
                    damage = battle_participants[bank_attacker].max_hp >> 4;
                    if (damage == 0)
                        damage = 1;

                    if (ability_effect && ability == ABILITY_ICE_BODY)
                        damage *= -1;
                }
            }
        }
    }
    damage_loc = damage;
    return;
}

void atkE2_switchout_abilities()
{
    active_bank = get_battle_bank(read_byte(battlescripts_curr_instruction + 1));
    if (has_ability_effect(active_bank, 0, 1))
    {
        u8 second_arg = bits_table[battle_stuff_ptr.ptr->field_58[active_bank]];
        switch (battle_participants[active_bank].ability_id)
        {
        case ABILITY_NATURAL_CURE:
            battle_participants[active_bank].status.int_status = 0;
            prepare_setattributes_in_battle(0, 0x28, second_arg, 4, &battle_participants[active_bank].status);
            mark_buffer_bank_for_execution(active_bank);
            break;
        case ABILITY_REGENERATOR:
            {
                u16 *current_hp = &battle_participants[active_bank].current_hp;
                u16 *max_hp = &battle_participants[active_bank].max_hp;
                if (current_hp)
                {
                    u8 added_hp = __udivsi3(*max_hp, 3);
                    if (*current_hp + added_hp > *max_hp)
                    {
                        added_hp = *max_hp - *current_hp;
                    }
                    *current_hp += added_hp;
                    prepare_setattributes_in_battle(0, 0x2A, second_arg, 4, current_hp);
                    mark_buffer_bank_for_execution(active_bank);
                }
                break;
            }
        }
    }
    battlescripts_curr_instruction += 2;
    return;
}

void atk8D_multihit_move_loop_counter()
{
    if (read_byte(battlescripts_curr_instruction + 1) != 0)
        multihit_counter = 0;
    else
    {
        if (has_ability_effect(bank_attacker, 0, 1) && battle_participants[bank_attacker].ability_id == ABILITY_SKILL_LINK)
            multihit_counter = 5;
        else
            multihit_counter = __umodsi3(rng(), 4) + 2;
    }
    battlescripts_curr_instruction += 2;
    return;
}

void atk42_jump_if_type()
{
    if (is_of_type(get_battle_bank(read_byte(battlescripts_curr_instruction + 1)), read_byte(battlescripts_curr_instruction + 2)))
        battlescripts_curr_instruction = (void*)read_word(battlescripts_curr_instruction + 3);
    else
        battlescripts_curr_instruction += 7;
    return;
}

void atk7F_set_leech_seed()
{
    if (move_outcome.missed || move_outcome.not_affected || move_outcome.failed || status3[bank_target].leech_seed)
    {
        move_outcome.missed = 1;
        battle_communication_struct.multistring_chooser = 1;
    }
    else if (is_of_type(bank_target, TYPE_GRASS))
    {
        move_outcome.missed = 1;
        battle_communication_struct.multistring_chooser = 2;
    }
    else
    {
        status3[bank_target].leech_seed_hp_receiver |= bank_attacker;
        status3[bank_target].leech_seed = 1;
        battle_communication_struct.multistring_chooser = 0;
    }
    return;
}

u16 get_airborne_state(u8 bank, u8 mode, u8 check_levitate);
u16 apply_type_effectiveness(u16 chained_effect, u8 move_type, u8 target_bank, u8 atk_bank, u8 airstatus);
u16 get_1_8_of_max_hp(u8 bank);
u8 can_poison(u8 bank, u8 self_inflicted);

u8 entry_hazards_hook()
{
    u8 effect = 0;
    u8 banks_side = is_bank_from_opponent_side(active_bank);
    struct side_affecting* ptr_to_struct = &new_battlestruct.ptr->side_affecting[banks_side];
    if (ptr_to_struct->lunardance && !ptr_to_struct->lunardance_done)
    {
        ptr_to_struct->lunardance_done = 1;
        damage_loc = (battle_participants[active_bank].max_hp - battle_participants[active_bank].current_hp) * -1;
        battle_participants[active_bank].status.int_status = 0;
        prepare_setattributes_in_battle(0, REQUEST_STATUS_BATTLE, 0, 4, &battle_participants[active_bank].status);
        mark_buffer_bank_for_execution(active_bank);
        //heal pp
        battlescript_push();
        battlescripts_curr_instruction = &lunardance_bs;
        effect = 1;
    }
    else if (side_affecting_halfword[banks_side].spikes_on && !(side_affecting_halfword[banks_side].spikes_damage_done) && get_airborne_state(active_bank, 0, 1) <= 2)
    {
        side_affecting_halfword[banks_side].spikes_damage_done = 1;
        if (has_ability_effect(active_bank, 0, 1) && battle_participants[active_bank].ability_id == ABILITY_MAGIC_GUARD)
        {
            damage_loc = 0;
        }
        else
        {
            u32 damage = __udivsi3(battle_participants[active_bank].max_hp, 5 - side_timers[banks_side].spikes_amount);
            if (damage == 0)
                damage = 1;
            damage_loc = damage;
        }
        battlescript_push();
        battlescripts_curr_instruction = &spikes_bs;
        effect = 1;
    }
    else if (ptr_to_struct->stealthrock && !ptr_to_struct->stealthrock_done)
    {
        ptr_to_struct->stealthrock_done = 1;
        if (has_ability_effect(active_bank, 0, 1) && battle_participants[active_bank].ability_id == ABILITY_MAGIC_GUARD)
        {
            damage_loc = 0;
        }
        else
        {
            u32 damage = get_1_8_of_max_hp(active_bank);
            damage = (damage * apply_type_effectiveness(64, TYPE_ROCK, active_bank, active_bank ^1, get_airborne_state(active_bank, 1, 0))) >> 6;
            if (damage == 0)
                damage = 1;
            damage_loc = damage;
        }
        battlescript_push();
        battlescripts_curr_instruction = &stealhrock_bs;
        effect = 1;
    }
    else if (ptr_to_struct->sticky_web && !ptr_to_struct->sticky_web_done && battle_participants[active_bank].spd_buff != 0 && get_airborne_state(active_bank, 0, 1) <= 2)
    {
        ptr_to_struct->sticky_web_done = 1;
        battlescript_push();
        battlescripts_curr_instruction = &stickyweb_bs;
        battle_scripting.stat_changer = 0x93;
        effect = 1;
    }
    else if (ptr_to_struct->toxic_spikes_psn && !ptr_to_struct->toxic_spikes_done && get_airborne_state(active_bank, 0, 1) <= 2)
    {
        ptr_to_struct->toxic_spikes_done = 1;
        if (is_of_type(active_bank, TYPE_POISON))
        {
            effect = 1;
            ptr_to_struct->toxic_spikes_psn = 0;
            battlescript_push();
            battlescripts_curr_instruction = &toxicpikes_absorbed;
        }
        else if (can_poison(active_bank, 0))
        {
            if (ptr_to_struct->toxic_spikes_badpsn)
                battle_participants[active_bank].status.flags.toxic_poison = 1;
            else
                battle_participants[active_bank].status.flags.poison = 1;
            battlescript_push();
            battlescripts_curr_instruction = &toxicspikes_bs;
            effect = 1;
            prepare_setattributes_in_battle(0, 0x28, 0, 4, &battle_participants[active_bank].status.flags);
            mark_buffer_bank_for_execution(active_bank);
        }
    }
    if (effect)
    {
       new_battlestruct.ptr->various.var1 = active_bank;
       battle_participants[active_bank].status2.destinny_bond = 0;
       hitmarker &= 0xFFFFFFBF; //same as above
    }
    return effect;
}

void switchin_newstruct_update()
{
    struct bank_affecting* ptr_to_struct = &new_battlestruct.ptr->bank_affecting[active_bank];
    struct bank_affecting previous_struct = new_battlestruct.ptr->bank_affecting[active_bank];
    memset(ptr_to_struct, 0, sizeof(struct bank_affecting));
    ptr_to_struct->type3 = TYPE_EGG;
    ptr_to_struct->just_switched_in = 1;
    if (current_move == MOVE_BATON_PASS)
    {
        ptr_to_struct->aqua_ring = previous_struct.aqua_ring;
        ptr_to_struct->embargo = previous_struct.embargo;
        ptr_to_struct->powertrick = previous_struct.powertrick;
        ptr_to_struct->gastro_acided = previous_struct.gastro_acided;
        ptr_to_struct->heal_block = previous_struct.heal_block;
        ptr_to_struct->healblock_duration = previous_struct.healblock_duration;
    }
    struct side_affecting* side_ptr = &new_battlestruct.ptr->side_affecting[is_bank_from_opponent_side(active_bank)];
    side_ptr->stealthrock_done = 0;
    side_ptr->sticky_web_done = 0;
    side_ptr->toxic_spikes_done = 0;
    side_ptr->lunardance_done = 0;
    return;
}

u8 get_attacking_move_type();
u8 item_battle_effects(u8 switchid, u8 bank, u8 move_turn);

u8 not_magicguard(u8 bank)
{
    if (battle_participants[bank].ability_id == ABILITY_MAGIC_GUARD && has_ability_effect(bank, 0, 1))
        return 0;
    return 1;
}

void atk49_move_end_turn()
{
    u8 effect = 0;
    //u16 last_move;
    //if (last_used_move == 0xFFFF)
      //  last_move = 0;
    //else
      //  last_move = last_used_move;
    u8 arg1 = read_byte(battlescripts_curr_instruction + 1);
    u8 arg2 = read_byte(battlescripts_curr_instruction + 2);
    u8 attacker_item = get_item_effect(bank_attacker, 1);
    u8 current_move_type = get_attacking_move_type();
    struct battle_participant* target_struct = &battle_participants[bank_target];
    struct battle_participant* attacker_struct = &battle_participants[bank_attacker];
    while (effect == 0)
    {
        switch (battle_scripting.cmd49_state_tracker)
        {
        case 0: //life orb damage, I think it should go first
            if (attacker_struct->current_hp && new_battlestruct.ptr->bank_affecting[bank_attacker].life_orbed && !new_battlestruct.ptr->bank_affecting[bank_attacker].sheerforce_bonus && not_magicguard(bank_attacker))
            {
                u32 damage = __udivsi3(attacker_struct->max_hp, 10);
                if (damage == 0)
                    damage = 1;
                damage_loc = damage;
                battlescript_push();
                battlescripts_curr_instruction = &lifeorb_damage;
                record_usage_of_item(bank_attacker, ITEM_EFFECT_LIFEORB);
                effect = 1;
            }
            battle_scripting.cmd49_state_tracker++;
            new_battlestruct.ptr->bank_affecting[bank_attacker].life_orbed = 0;
            new_battlestruct.ptr->bank_affecting[bank_attacker].sheerforce_bonus = 0;
            break;
        case 1: //spiky shield recoil
            if (new_battlestruct.ptr->bank_affecting[bank_attacker].spikyshield_damage && attacker_struct->current_hp && not_magicguard(bank_attacker))
            {
                effect = 1;
                damage_loc = get_1_8_of_max_hp(bank_attacker);
                battlescript_push();
                battlescripts_curr_instruction = &spikyshield_dam_bs;
                new_battlestruct.ptr->bank_affecting[bank_attacker].spikyshield_damage = 0;
                move_outcome.missed = 0;
            }
            battle_scripting.cmd49_state_tracker++;
            break;
        case 2: //kings shield attak stat loss
            if (new_battlestruct.ptr->bank_affecting[bank_attacker].kingsshield_damage && attacker_struct->atk_buff != 0)
            {
                new_battlestruct.ptr->bank_affecting[bank_attacker].kingsshield_damage = 0;
                battle_scripting.stat_changer = 0xA1;
                move_outcome.missed = 0;
                battlescript_push();
                battlescripts_curr_instruction = &statloss_bs;
                effect = 1;
            }
            battle_scripting.cmd49_state_tracker++;
            break;
        case 3: //rage checker
            if (target_struct->current_hp && target_struct->status2.raged && bank_target != bank_attacker &&
                is_bank_from_opponent_side(bank_target) != is_bank_from_opponent_side(bank_attacker) && MOVE_WORKED && TARGET_TURN_DAMAGED &&
                DAMAGING_MOVE && target_struct->atk_buff != 0xC)
            {
                target_struct->atk_buff++;
                battlescript_push();
                battlescripts_curr_instruction = (void*) 0x082DAE0D; //rage is building
                effect = 1;
            }
            battle_scripting.cmd49_state_tracker++;
            break;
        case 4: //defrosting via fire type move
            if (target_struct->current_hp && target_struct->status.flags.freeze && TARGET_TURN_DAMAGED && MOVE_WORKED && current_move_type == TYPE_FIRE)
            {
                target_struct->status.flags.freeze = 0;
                active_bank = bank_target;
                battlescript_push();
                battlescripts_curr_instruction = (void*) 0x082DB282; //defrosting
                effect = 1;
                prepare_setattributes_in_battle(0, REQUEST_STATUS_BATTLE, 0, 4, &target_struct->status);
                mark_buffer_bank_for_execution(active_bank);
            }
            battle_scripting.cmd49_state_tracker++;
            break;
        case 5: //target's synchronize
            if (ability_battle_effects(7, bank_target, 0, 0, 0))
                effect = 1;
            battle_scripting.cmd49_state_tracker++;
            break;
        case 6: //contact abilities
            if (ability_battle_effects(4, bank_target, 0, 0, 0))
                effect = 1;
            battle_scripting.cmd49_state_tracker++;
            break;
        case 7: //target's items
            if (item_battle_effects(2, bank_target, 0))
                effect = 1;
            battle_scripting.cmd49_state_tracker++;
            break;
        case 8: //status immunnities
            if (ability_battle_effects(5, 0, 0, 0, 0))
            {
                effect = 1;
                break;
            }
            battle_scripting.cmd49_state_tracker++;
            break;
        case 9: //attacker synchronize
            if (ability_battle_effects(8, bank_attacker, 0, 0, 0))
                effect = 1;
            battle_scripting.cmd49_state_tracker++;
            break;
        case 10: //choice move update
            {
                u16* choice_move = &battle_stuff_ptr.ptr->choiced_move[bank_attacker];
                if (attacker_item == CHOICE_ITEM && last_used_move != MOVE_STRUGGLE &&hitmarker & 0x2000000 && (*choice_move == 0 || *choice_move == 0xFFFF))
                {
                    if ((last_used_move == MOVE_BATON_PASS || last_used_move == MOVE_VOLT_SWITCH || last_used_move == MOVE_UTURN) && move_outcome.failed)
                    {
                        break;
                    }
                    last_used_move = *choice_move;
                }
                if (get_move_position(bank_attacker, *choice_move) == -1)
                    *choice_move = 0;
                battle_scripting.cmd49_state_tracker++;
                break;
            }
        case 11: //held items
            {
                for (u8 i = 0; i < no_of_all_banks; i++)
                {
                    if (battle_stuff_ptr.ptr->changed_held_items[i])
                        battle_participants[i].held_item = 0;
                }

                battle_scripting.cmd49_state_tracker++;
                break;
            }
        case 12: //no idea what it is
            if (status3[bank_attacker].underground || status3[bank_attacker].underwater || status3[bank_attacker].on_air || new_battlestruct.ptr->bank_affecting[bank_attacker].sky_drop_attacker || new_battlestruct.ptr->bank_affecting[bank_attacker].sky_drop_target)
            {
                if (!(hitmarker & HITMARKER_NO_ANIMATIONS))
                {
                    active_bank = bank_attacker;
                    //function
                    mark_buffer_bank_for_execution(active_bank);
                }
            }
            battle_scripting.cmd49_state_tracker++;
            break;
        case 13: //to do
            battle_scripting.cmd49_state_tracker++;
            break;
        case 14: //to do
            battle_scripting.cmd49_state_tracker++;
            break;
        case 15: //item move end turn
            if (item_battle_effects(3, 0, 0))
            {
                effect = 1;
                break;
            }
            battle_scripting.cmd49_state_tracker++;
            break;
        case 16: //cheek pouch and berry adder
            {
                for (u8 i = 0; i < no_of_all_banks; i++)
                {
                    if (new_battlestruct.ptr->bank_affecting[i].eaten_berry)
                    {
                        new_battlestruct.ptr->bank_affecting[i].eaten_berry = 0;
                        if (check_ability(i, ABILITY_CHEEK_POUCH) && battle_participants[i].current_hp != battle_participants[i].max_hp)
                        {
                            effect = 1;
                            s32 damage = __udivsi3(battle_participants[i].max_hp, 3);
                            if (damage == 0)
                                damage = 1;
                            if (battle_participants[i].current_hp + damage > battle_participants[i].max_hp)
                                damage = battle_participants[i].max_hp - battle_participants[i].current_hp;
                            damage_loc = damage * -1;
                            battlescript_push();
                            battlescripts_curr_instruction = &cheekpouch_bs;
                            bank_target = i;
                            record_usage_of_ability(i, ABILITY_CHEEK_POUCH);
                            break;
                        }
                    }
                }
                if (effect == 0)
                    battle_scripting.cmd49_state_tracker++;
            }
            break;
        case 17:
            {
                for (u8 i = 0; i < no_of_all_banks; i++)
                {
                    if (disable_structs[i].substitute_hp == 0)
                    {
                        battle_participants[i].status2.substitute = 0;
                    }
                }
                battle_scripting.cmd49_state_tracker++;
            }
            break;
        case 18: //magic bounce and coat eraser; aviods endless loops if magic bounce meets magic bounce or magic coat
            new_battlestruct.ptr->various.magicbounce = 0;
            battle_scripting.cmd49_state_tracker++;
            break;
        case 19: //symbiosis item passing
            {
                for (u8 i = 0; i < no_of_all_banks; i++)
                {
                    if (new_battlestruct.ptr->bank_affecting[i].item_used)
                    {
                        new_battlestruct.ptr->bank_affecting[i].item_used = 0;
                        if (ability_battle_effects(20, i, ABILITY_SYMBIOSIS, 0, 0) && battle_participants[i].held_item == 0 && battle_participants[i ^ 2].held_item)
                        {
                            effect = 1;
                            battle_participants[i].held_item = battle_participants[i ^ 2].held_item;
                            battle_participants[i ^ 2].held_item = 0;
                            active_bank = i;
                            prepare_setattributes_in_battle(0, 2, 0, 2, &battle_participants[i].held_item);
                            mark_buffer_bank_for_execution(active_bank);
                            active_bank = i ^ 2;
                            prepare_setattributes_in_battle(0, 2, 0, 2, &battle_participants[i ^ 2].held_item);
                            mark_buffer_bank_for_execution(active_bank);
                            battlescript_push();
                            battlescripts_curr_instruction = &symbiosispass_bs;
                            battle_scripting.active_bank = i;
                            bank_target = i ^ 2;
                            record_usage_of_ability(i ^ 2, ABILITY_SYMBIOSIS);
                        }
                    }
                }
                if (effect == 0)
                    battle_scripting.cmd49_state_tracker++;
            }
            break;
        case 20:
            battle_scripting.cmd49_state_tracker++;
            break;
        }
        #define case_max 20
        if (arg1 == 1 && effect == 0)
            battle_scripting.cmd49_state_tracker = case_max;
        else if (arg1 == 2 && arg2 == battle_scripting.cmd49_state_tracker)
            battle_scripting.cmd49_state_tracker = case_max;
        if (battle_scripting.cmd49_state_tracker == case_max)
            break;
    }
    if (battle_scripting.cmd49_state_tracker == case_max && effect == 0)
        battlescripts_curr_instruction += 3;
    return;
}

u8 percent_chance(u8 percent);

u8 move_thaws_user(u16 move)
{
    if (move == MOVE_FLAME_WHEEL || move == MOVE_SACRED_FIRE || move == MOVE_SCALD|| move == MOVE_FLARE_BLITZ || move == MOVE_FUSION_FLARE || move == MOVE_STEAM_ERUPTION)
        return 1;
    return 0;
}

u8 healblock_forbidden_moves(u16 move, u8 with_leechseed)
{
    if (move == MOVE_ABSORB || move == MOVE_MEGA_DRAIN || move == MOVE_GIGA_DRAIN|| move == MOVE_LEECH_LIFE || move == MOVE_DRAINING_KISS || move == MOVE_DRAIN_PUNCH || move == MOVE_DREAM_EATER || move == MOVE_HORN_LEECH || move == MOVE_OBLIVION_WING || move == MOVE_PARABOLIC_CHARGE || move == MOVE_MILK_DRINK || move == MOVE_HEAL_BLOCK || move == MOVE_REST || move == MOVE_RECOVER || move == MOVE_MOONLIGHT || move == MOVE_MORNING_SUN || move == MOVE_SLACK_OFF || move == MOVE_SYNTHESIS || move == MOVE_ROOST || move == MOVE_SOFTBOILED)
        return 1;
    else if (move == MOVE_LEECH_SEED && with_leechseed)
        return 1;
    return 0;
}

u8 gravity_forbidden_move(u16 move)
{
    if (move == MOVE_TELEKINESIS || move == MOVE_MAGNET_RISE || move == MOVE_SPLASH|| move == MOVE_BOUNCE || move == MOVE_FLY || move == MOVE_FLYING_PRESS || move == MOVE_JUMP_KICK || move == MOVE_HIGH_JUMP_KICK || move == MOVE_SKY_DROP)
        return 1;
    return 0;
}

u8 embargo_forbidden_move(u16 move)
{
    if (move == MOVE_FLING)
        return 1;
    return 0;
}

void damage_calc(u16 move, u8 move_type, u8 atk_bank, u8 def_bank);

u8 check_if_cannot_attack()
{
    u8 effect = 0;
    struct battle_participant* attacker_struct = &battle_participants[bank_attacker];
    u8* state_tracker = &battle_stuff_ptr.ptr->atk_canceller_state_tracker;
    while(effect == 0)
    {
        switch (*state_tracker)
        {
        case 0: //flag clear
            attacker_struct->status2.destinny_bond = 0;
            status3[bank_attacker].grudge = 0;
            break;
        case 1: //check if asleep
            if (attacker_struct->status.flags.sleep)
            {
                if (uproar_wakeup_check(bank_attacker))
                {
                    effect = 2;
                    attacker_struct->status.flags.sleep = 0;
                    attacker_struct->status2.nightmare = 0;
                    battle_communication_struct.multistring_chooser = 1;
                    battlescript_push();
                    battlescripts_curr_instruction = (void*) 0x82DB220;
                }
                else
                {
                    if (check_ability(bank_attacker, ABILITY_EARLY_BIRD))
                        attacker_struct->status.flags.sleep -= 2;
                    else
                        attacker_struct->status.flags.sleep--;
                    if (attacker_struct->status.flags.sleep == 0)
                    {
                        effect = 2;
                        attacker_struct->status2.nightmare = 0;
                        battle_communication_struct.multistring_chooser = 0;
                        battlescript_push();
                        battlescripts_curr_instruction = (void*) 0x82DB220;
                    }
                    else if (current_move == MOVE_SLEEP_TALK || current_move == MOVE_SNORE)
                    {
                        effect = 1;
                        hitmarker |= 0x80000;
                        battlescripts_curr_instruction = (void*) 0x82DB213;
                    }
                }
            }
            break;
        case 2: //check if frozen
            if (attacker_struct->status.flags.freeze)
            {
                if (percent_chance(20))
                {
                    attacker_struct->status.flags.freeze = 0;
                    effect = 2;
                    battle_communication_struct.multistring_chooser = 0;
                    battlescript_push();
                    battlescripts_curr_instruction = (void*) 0x82DB277;
                }
                else if (!move_thaws_user(current_move))
                {
                    effect = 1;
                    battlescripts_curr_instruction = (void*) 0x82DB26A;
                    hitmarker |= HITMARKER_NO_ATTACKSTRING;
                }
            }
            break;
        case 3: //check truant
            if (check_ability(bank_attacker, ABILITY_TRUANT) && disable_structs[bank_attacker].truant_counter & 1)
            {
                battle_communication_struct.multistring_chooser = 0;
                battlescripts_curr_instruction = (void*) 0x082DB6AD;
                move_outcome.missed = 1;
                effect = 3;
            }
            break;
        case 4: //check recharge
            if (attacker_struct->status2.recharge)
            {
                attacker_struct->status2.recharge = 0;
                disable_structs[bank_attacker].field19[0] = 0;
                battlescripts_curr_instruction = (void*) 0x82D9462;
                effect = 3;
            }
            break;
        case 5: //check flinched
            if (attacker_struct->status2.flinched)
            {
                attacker_struct->status2.flinched = 0;
                battlescripts_curr_instruction = (void*) 0x82DB29B;
                effect = 3;
                protect_structs[bank_attacker].flag2_flinch_immobility = 1;
            }
            break;
        case 6: //check if attack is disabled
            if (disable_structs[bank_attacker].disabled_move == current_move && current_move)
            {
                protect_structs[bank_attacker].flag1_used_disabled_move = 1;
                battle_scripting.active_bank = bank_attacker;
                battlescripts_curr_instruction = (void*) 0x82DAE14;
                effect = 3;
            }
            break;
        case 7: //check if can't use move due to taunt
            if (disable_structs[bank_attacker].taunt_timer && move_table[current_move].split == 2)
            {
                effect = 3;
                protect_structs[bank_attacker].flag2_used_taunted_move = 1;
                battlescripts_curr_instruction = (void*) 0x82DB0A4;
            }
            break;
        case 8: //check imprisioned
            if (check_if_imprisioned(bank_attacker, current_move))
            {
                effect = 3;
                protect_structs[bank_attacker].flag1_used_imprisoned_move = 1;
                battlescripts_curr_instruction = (void*) 0x82DB176;
            }
            break;
        case 9: //check heal block
            if (new_battlestruct.ptr->bank_affecting[bank_attacker].heal_block && healblock_forbidden_moves(current_move, 0))
            {
                effect = 4;
                battlescripts_curr_instruction = &healblock_prevents_usage_bs;
            }
            break;
        case 10: //check gravity
            if (new_battlestruct.ptr->field_affecting.gravity && gravity_forbidden_move(current_move))
            {
                effect = 4;
                battlescripts_curr_instruction = &gravity_prevents_usage_bs;
            }
            break;
        case 11: //check embargo
            if (new_battlestruct.ptr->bank_affecting[bank_attacker].embargo && embargo_forbidden_move(current_move))
            {
                effect = 4;
                battlescripts_curr_instruction = &embargoprevents_usage_bs;
            }
            break;
        case 12: //check confusion
            if (attacker_struct->status2.confusion)
            {
                attacker_struct->status2.confusion--;
                if (attacker_struct->status2.confusion == 0)
                {
                    battlescript_push();
                    battlescripts_curr_instruction = (void*) 0x82DB300; //snapped out of confusion
                }
                else if (percent_chance(50)) //hits itself
                {
                    battlescript_push();
                    battlescripts_curr_instruction = (void*) 0x82DB2BD;
                    battle_communication_struct.multistring_chooser = 1;
                }
                else //manages to hit the target
                {
                    battlescript_push();
                    battlescripts_curr_instruction = (void*) 0x82DB2BD;
                    battle_communication_struct.multistring_chooser = 0;
                    bank_target = bank_attacker;
                    damage_calc(MOVE_POUND, TYPE_EGG, bank_attacker, bank_attacker);
                    protect_structs[bank_attacker].flag1_confusion_self_damage = 1;
                    hitmarker |= 0x80000;
                }
                effect = 1;
            }
            break;
        case 13: //check paralysis
            if (attacker_struct->status.flags.paralysis && percent_chance(25))
            {
                effect = 1;
                protect_structs[bank_attacker].flag0_prlz_immobility = 1;
                battlescripts_curr_instruction = (void*) 0x82DB28B;
                hitmarker |= 0x80000;
            }
            break;
        case 14: //check infatuation
            if (attacker_struct->status2.in_love)
            {
                battle_scripting.active_bank = get_bank_in_love(attacker_struct->status2.in_love);
                if (percent_chance(50)) //in love cannot attack
                {
                    battlescript_custom_push((void*)0x82DB334);
                    battlescripts_curr_instruction = (void*) 0x82DB327;
                    protect_structs[bank_attacker].flag1_love_immobility = 1;
                    effect = 3;
                }
                else
                {
                    battlescript_push();
                    battlescripts_curr_instruction = (void*) 0x82DB327;
                    effect = 1;
                }
            }
            break;
        case 15: //check bide
            break;
        case 16: //aroma veil protection
            if (current_move == MOVE_TORMENT || current_move == MOVE_TAUNT || current_move == MOVE_HEAL_BLOCK || current_move == MOVE_DISABLE || current_move == MOVE_ATTRACT || current_move == MOVE_ENCORE)
            {
                u8 aroma = ability_battle_effects(12, bank_target, ABILITY_AROMA_VEIL, 1, 0);
                if (aroma)
                {
                    effect = 4;
                    battlescripts_curr_instruction = &aromaveilprevents_bs;
                    last_used_ability = ABILITY_AROMA_VEIL;
                    record_usage_of_ability(aroma - 1, ABILITY_AROMA_VEIL);
                }
            }
            break;
        case 17: //check thawing effect
            if (attacker_struct->status.flags.freeze && move_thaws_user(current_move))
            {
                attacker_struct->status.flags.freeze = 0;
                battlescript_push();
                battlescripts_curr_instruction = (void*) 0x82DB277;
                battle_communication_struct.multistring_chooser = 1;
            }
            break;
        }
        if (effect == 2)
        {
            active_bank = bank_attacker;
            prepare_setattributes_in_battle(0, REQUEST_STATUS_BATTLE, 0, 4, &attacker_struct->status);
            mark_buffer_bank_for_execution(active_bank);
        }
        else if (effect >= 3)
        {
            hitmarker |= 0x80000;
            reset_several_turns_stuff(bank_attacker);
            if (effect == 4)
            {
                battle_text_buff1[0] = 0xFD;
                battle_text_buff1[1] = 2;
                battle_text_buff1[2] = current_move;
                battle_text_buff1[3] = (current_move >> 8);
                battle_text_buff1[4] = 0xFF;
            }
        }
        state_tracker++;
        if (*state_tracker >= 17 && effect == 0)
            break;
    }
    return effect;
}

u8 find_move_in_table(u16 move, u16 table_ptr[]);

u8 immune_to_powder_moves(u8 def_bank, u16 move)
{
    u8 immune = 0;
    if (find_move_in_table(move, &powder_moves[0]))
    {
        if (is_of_type(def_bank, TYPE_GRASS))
        {
            immune = 1;
            battlescripts_curr_instruction = &no_effect_bs;
        }
        else if (get_item_effect(def_bank, 1) == ITEM_EFFECT_SAFETYGOOGLES)
        {
            immune = 1;
            record_usage_of_item(def_bank, ITEM_EFFECT_SAFETYGOOGLES);
            battlescripts_curr_instruction = &no_effect_bs;
        }
    }
    return immune;
}

u8 protect_affects(u16 move, u8 set);

void atk00_move_canceller()
{
    if (battle_outcome)
    {
        battle_state_flags.flag4 = 1;
        battle_state_flags.flag8 = 1;
        return;
    }
    else if (battle_participants[bank_attacker].current_hp == 0 && !(hitmarker & HITMARKER_NO_ATTACKSTRING))
    {
        hitmarker |= 0x80000;
        battlescripts_curr_instruction = (void*) 0x082D8A4E; //bs_endturn and end
        return;
    }
    else if (check_if_cannot_attack())
        return;
    else if (ability_battle_effects(2, bank_target, 0, 0, 0))
        return;
    else if (immune_to_powder_moves(bank_target, current_move))
        return;
    else if (battle_participants[bank_attacker].current_pp[current_move_position] == 0 && current_move != MOVE_STRUGGLE && ((hitmarker & (HITMARKER_NO_ATTACKSTRING || 0x800000)) == 0)) //bide check later when status2 becomes usable
    {
        move_outcome.missed = 1;
        battlescripts_curr_instruction = (void*) 0x082DB07A; //no pp bs
        return;
    }
    hitmarker &= 0xFF7FFFFF;
    if ((hitmarker & 0x2000000) == 0) // and no bide
    {
        u8 disobedient = is_poke_disobedient();
        if (disobedient == 2)
        {
            hitmarker |= 0x2000000;
            return;
        }
        else if (disobedient)
        {
            move_outcome.missed = 1;
            return;
        }
    }
    if (protect_structs[bank_target].flag0_bouncemove && move_table[current_move].move_flags.flags.affected_by_magic_coat && new_battlestruct.ptr->various.magicbounce == 0) //magic coat check
    {
        protect_structs[bank_target].flag0_bouncemove = 0;
        pressure_pp_lose(bank_attacker, bank_target, MOVE_MAGIC_COAT);
        battlescript_push();
        battlescripts_curr_instruction = (void*) 0x082DB194;
        new_battlestruct.ptr->various.magicbounce = 1;
        return;
    }
    else if ((battle_participants[bank_target].ability_id == ABILITY_MAGIC_BOUNCE && has_ability_effect(bank_target, 1, 1)) && move_table[current_move].move_flags.flags.affected_by_magic_coat && new_battlestruct.ptr->various.magicbounce == 0)
    {
        new_battlestruct.ptr->various.magicbounce = 1;
        battlescript_push();
        battlescripts_curr_instruction = &magicbounce_bs;
        return;
    }
    for (u8 i = 0; i < no_of_all_banks; i++)
    {
        if (protect_structs[turn_order[i]].flag0_stealmove && move_table[current_move].move_flags.flags.affected_by_snatch)
        {
            pressure_pp_lose(bank_attacker, bank_target, MOVE_SNATCH);
            protect_structs[turn_order[i]].flag0_stealmove = 0;
            battle_scripting.active_bank = turn_order[i];
            battlescript_push();
            battlescripts_curr_instruction = (void*) 0x82DB1AC;
            return;
        }
    }
    if (special_statuses[bank_target].lightning_rod_redirected)
    {
        special_statuses[bank_target].lightning_rod_redirected = 0;
        if (new_battlestruct.ptr->various.stormdrain)
        {
            new_battlestruct.ptr->various.stormdrain = 0;
            last_used_ability = ABILITY_STORM_DRAIN;
        }
        else
            last_used_ability = ABILITY_LIGHTNING_ROD;
        battlescript_push();
        battlescripts_curr_instruction = (void*) 0x082DB53E;
        record_usage_of_ability(bank_target, last_used_ability);
        return;
    }
    if (protect_affects(current_move, 0)
        && !(check_if_twoturns_move(current_move) && battle_participants[bank_attacker].status2.multiple_turn_move)
        && !(current_move == MOVE_CURSE && is_of_type(bank_attacker, TYPE_GHOST)))
    {
        battle_communication_struct.field6 = 1;
        move_outcome.missed = 1;
        reset_several_turns_stuff(bank_attacker);
        sth_with_moves1[bank_target] = 0;
        sth_with_moves2[bank_target] = 0;
    }

    battlescripts_curr_instruction++;
    return;
}