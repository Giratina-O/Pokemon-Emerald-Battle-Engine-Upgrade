#ifndef B_SCRIPTS
#define B_SCRIPTS

#include "types.h"

//tables

u16 forewarn_moves[] = {MOVE_CRUSH_GRIP, MOVE_DRAGON_RAGE, MOVE_ENDEAVOR, MOVE_FLAIL, MOVE_REVERSAL, MOVE_FRUSTRATION, MOVE_GRASS_KNOT, MOVE_GYRO_BALL, MOVE_HIDDEN_POWER, MOVE_LOW_KICK, MOVE_NATURAL_GIFT, MOVE_NIGHT_SHADE, MOVE_PSYWAVE, MOVE_RETURN, MOVE_SEISMIC_TOSS, MOVE_SONIC_BOOM, MOVE_TRUMP_CARD, MOVE_WRING_OUT, 0xFFFF};
u16 sound_moves[] = {MOVE_BOOMBURST, MOVE_BUG_BUZZ, MOVE_CHATTER, MOVE_CONFIDE, MOVE_DISARMING_VOICE, MOVE_ECHOED_VOICE, MOVE_GRASS_WHISTLE, MOVE_GROWL, MOVE_HEAL_BELL, MOVE_HYPER_VOICE, MOVE_METAL_SOUND, MOVE_NOBLE_ROAR, MOVE_PARTING_SHOT, MOVE_PERISH_SONG, MOVE_RELIC_SONG, MOVE_ROAR, MOVE_ROUND, MOVE_SCREECH, MOVE_SING, MOVE_SNARL, MOVE_SNORE, MOVE_SUPERSONIC, MOVE_UPROAR, 0xFFFF};
u16 powder_moves[] = {MOVE_COTTON_SPORE, MOVE_POISON_POWDER, MOVE_POWDER, MOVE_RAGE_POWDER, MOVE_SLEEP_POWDER, MOVE_SPORE, MOVE_STUN_SPORE, 0xFFFF};
u16 ball_bomb_moves[] = {MOVE_ACID_SPRAY, MOVE_AURA_SPHERE, MOVE_BARRAGE, MOVE_BULLET_SEED, MOVE_EGG_BOMB, MOVE_ELECTRO_BALL, MOVE_ENERGY_BALL, MOVE_FOCUS_BLAST, MOVE_GYRO_BALL, MOVE_ICE_BALL, MOVE_MAGNET_BOMB, MOVE_MIST_BALL, MOVE_MUD_BOMB, MOVE_OCTAZOOKA, MOVE_ROCK_WRECKER, MOVE_SEARING_SHOT, MOVE_SEED_BOMB, MOVE_SLUDGE_BOMB, MOVE_WEATHER_BALL, MOVE_ZAP_CANNON, 0xFFFF};
u16 reckless_moves_table[] = {MOVE_BRAVE_BIRD, MOVE_DOUBLEEDGE, MOVE_FLARE_BLITZ, MOVE_HEAD_CHARGE, MOVE_HEAD_SMASH, MOVE_HIGH_JUMP_KICK, MOVE_JUMP_KICK, MOVE_SUBMISSION, MOVE_TAKE_DOWN, MOVE_LIGHT_OF_RUIN, MOVE_VOLT_TACKLE, MOVE_WOOD_HAMMER, MOVE_WILD_CHARGE, 0xFFFF};
u16 ironfist_moves_table[] = {MOVE_BULLET_PUNCH, MOVE_COMET_PUNCH, MOVE_DIZZY_PUNCH, MOVE_DRAIN_PUNCH, MOVE_DYNAMIC_PUNCH, MOVE_FIRE_PUNCH, MOVE_FOCUS_PUNCH, MOVE_HAMMER_ARM, MOVE_ICE_PUNCH, MOVE_MACH_PUNCH, MOVE_MEGA_PUNCH, MOVE_METEOR_MASH, MOVE_POWERUP_PUNCH, MOVE_SHADOW_PUNCH, MOVE_SKY_UPPERCUT, MOVE_THUNDER_PUNCH, 0xFFFF};
u16 sheerforce_moves_table[] = {MOVE_WATERFALL, MOVE_IRON_HEAD, MOVE_STOMP, MOVE_ZEN_HEADBUTT, MOVE_ROCK_CLIMB, MOVE_ICE_FANG, MOVE_THUNDER_FANG, MOVE_FLASH_CANNON, MOVE_FIRE_FANG, MOVE_DARK_PULSE, MOVE_DRAGON_BREATH, MOVE_AIR_SLASH, MOVE_BITE, MOVE_CRUNCH, MOVE_ICE_PUNCH, MOVE_BULLDOZE, MOVE_POWERUP_PUNCH, MOVE_IRON_TAIL, MOVE_FLAMETHROWER, MOVE_FIRE_BLAST, MOVE_THUNDER, MOVE_THUNDERBOLT, MOVE_EARTH_POWER, MOVE_SLUDGE_BOMB, MOVE_SLUDGE_WAVE, MOVE_SHADOW_BALL, MOVE_POISON_JAB, MOVE_THUNDER_PUNCH, MOVE_FIRE_PUNCH, MOVE_SNORE, MOVE_SECRET_POWER, MOVE_ROCK_TOMB, MOVE_ROCK_SMASH, MOVE_ROCK_SLIDE, MOVE_ICY_WIND, MOVE_ICE_BEAM, MOVE_BLIZZARD, MOVE_WATER_PULSE, MOVE_FOCUS_BLAST, MOVE_POISON_STING, MOVE_POISON_TAIL, MOVE_POISON_FANG, MOVE_BODY_SLAM, MOVE_CONFUSION, MOVE_LOW_SWEEP, MOVE_ASTONISH, MOVE_PLAY_ROUGH, MOVE_CHARGE_BEAM, MOVE_FORCE_PALM, MOVE_FAKE_OUT, MOVE_DYNAMIC_PUNCH, MOVE_EXTRASENSORY, MOVE_MUD_SHOT, MOVE_ANCIENT_POWER, MOVE_METAL_CLAW, MOVE_SCALD, MOVE_BUBBLE, MOVE_BUBBLE_BEAM, MOVE_CRUSH_CLAW, MOVE_PSYCHIC, MOVE_GUNK_SHOT, MOVE_SNARL, MOVE_FLARE_BLITZ, MOVE_HEAT_WAVE, MOVE_FLAME_WHEEL, MOVE_FLAME_CHARGE, MOVE_HEADBUTT, MOVE_EMBER, MOVE_MUD_BOMB, MOVE_LAVA_PLUME, MOVE_TWISTER, MOVE_SKY_ATTACK, MOVE_DRAGON_RUSH, MOVE_STEEL_WING, MOVE_MUDSLAP, MOVE_SIGNAL_BEAM, MOVE_STRUGGLE_BUG, MOVE_ZAP_CANNON, MOVE_VOLT_TACKLE, MOVE_TWINEEDLE, MOVE_TRI_ATTACK, MOVE_STEAMROLLER, MOVE_THUNDER_SHOCK, MOVE_SPARK, MOVE_STEAM_ERUPTION, MOVE_SMOG, MOVE_SLUDGE, MOVE_SILVER_WIND, MOVE_SEED_FLARE, MOVE_SEARING_SHOT, MOVE_SACRED_FIRE, MOVE_ROLLING_KICK, MOVE_ACID_SPRAY, MOVE_ACID, MOVE_AURORA_BEAM, MOVE_BLAZE_KICK, MOVE_BLUE_FLARE, MOVE_BOLT_STRIKE, MOVE_BONE_CLUB, MOVE_BOUNCE, MOVE_BUG_BUZZ, MOVE_CHATTER, MOVE_CONSTRICT, MOVE_CROSS_POISON, MOVE_DIAMOND_STORM, MOVE_DISCHARGE, MOVE_DIZZY_PUNCH, MOVE_ELECTROWEB, MOVE_ENERGY_BALL, MOVE_FIERY_DANCE, MOVE_FREEZEDRY, MOVE_FREEZE_SHOCK, MOVE_GLACIATE, MOVE_HEART_STAMP, MOVE_HURRICANE, MOVE_HYPER_FANG, MOVE_ICE_BURN, MOVE_ICICLE_CRASH, MOVE_INFERNO, MOVE_LEAF_TORNADO, MOVE_LICK, MOVE_LUSTER_PURGE, MOVE_METEOR_MASH, MOVE_MIRROR_SHOT, MOVE_MIST_BALL, MOVE_MOONBLAST, MOVE_MUDDY_WATER, MOVE_MYSTICAL_FIRE, MOVE_NEEDLE_ARM, MOVE_NIGHT_DAZE, MOVE_NUZZLE, MOVE_OCTAZOOKA, MOVE_OMINOUS_WIND, MOVE_POWDER_SNOW, MOVE_PSYBEAM, MOVE_RELIC_SONG, MOVE_RAZOR_SHELL, 0xFFFF};
u16 biting_moves_table[] = {MOVE_BITE, MOVE_CRUNCH, MOVE_POISON_FANG, MOVE_FIRE_FANG, MOVE_ICE_FANG, MOVE_THUNDER_FANG, 0xFFFF};
u16 megalauncher_moves_table[] = {MOVE_WATER_PULSE, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_HEAL_PULSE, MOVE_DRAGON_PULSE, MOVE_ORIGIN_PULSE, 0xFFFF};

u8 transform_bs[] = {0x9B, 0x9, 0xA, 0x10, 0x7D, 0x00, 0x12, 0x40, 0x00, 0x83, 0x0, 0x0, 0x3F};
u8 snow_warning_bs[] = {0x39, 0x20, 0, 0x10, 0x7D, 0x01, 0x3A, 0x45, 0x7, 0xD, 0x0, 0x0, 0x0, 0x0, 0x41, 0x8D, 0xB4, 0x2D, 0x08, 0x3F};
u8 desolateland_bs[] = {0x39, 0x20, 0, 0x10, 0x7E, 0x01, 0x3A, 0x45, 0x7, 0xB, 0x0, 0x0, 0x0, 0x0, 0x41, 0x8D, 0xB4, 0x2D, 0x08, 0x3F};
u8 primoridalsea_bs[] = {0x39, 0x20, 0, 0x10, 0x7F, 0x01, 0x3A, 0x45, 0x7, 0xA, 0x0, 0x0, 0x0, 0x0, 0x41, 0x8D, 0xB4, 0x2D, 0x08, 0x3F};
u8 deltastream_bs[] = {0x39, 0x20, 0, 0x10, 0x80, 0x01, 0x12, 0x30, 0x0, 0x41, 0x8D, 0xB4, 0x2D, 0x08, 0x3F};
u8 forewarn_bs[] = {0x39, 0x20, 0, 0x10, 0x81, 0x01, 0x12, 0x30, 0x0, 0x3F};
u8 slowstart_bs[] = {0x39, 0x20, 0, 0x10, 0x82, 0x01, 0x12, 0x30, 0x0, 0x3F};
u8 anticipation_bs[] = {0x39, 0x20, 0, 0x10, 0x83, 0x01, 0x0, 0x12, 0x30, 0x0, 0x3F};
u8 cherrimswitch_bs[] = {0xE6, 0x3A, 0x10, 0x3A, 0x1, 0x12, 0x30, 0x0, 0x3F};
u8 dryskindamage_bs [] = {0x39, 0x20, 0, 0x83, 0x1, 0x0, 0x3A, 0x10, 0x84, 0x1, 0x12, 0x30, 0, 0x35, 0x80, 0x42, 0x02, 0x02, 0x00, 0x01, 0x00, 0x00, 0x0B, 0x01, 0x0C, 0x01, 0x19, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F};
u8 solarpower_bs[] = {0x39, 0x20, 0, 0x83, 0x1, 0x0, 0x3A, 0x10, 0x85, 0x1, 0x12, 0x30, 0, 0x35, 0x80, 0x42, 0x02, 0x02, 0x00, 0x01, 0x00, 0x00, 0x0B, 0x01, 0x0C, 0x01, 0x19, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3F};
u8 harvest_bs[] = {0x39, 0x20, 0, 0xEA, 0x6F, 0xB4, 0x2D, 0x08, 0x10, 0x86, 0x1, 0x12, 0x30, 0x0, 0x3F};
u8 healer_bs[] = {0x39, 0x20, 0, 0x10, 0x87, 0x1, 0x12, 0x40, 0, 0x98, 10, 0x3F};
u8 pickup_bs[] = {0x39, 0x20, 0, 0x10, 0x88, 0x1, 0x12, 0x40, 0, 0x3F};
u8 moldbreaker_message_bs[] = {0x39, 0x20, 0, 0x10, 0x89, 0x1, 0x12, 0x40, 0, 0x3F};
u8 turboblaze_bs[] = {0x39, 0x20, 0, 0x10, 0x8A, 0x1, 0x12, 0x40, 0, 0x3F};
u8 terravolt_bs[] = {0x39, 0x20, 0, 0x10, 0x8B, 0x1, 0x12, 0x40, 0, 0x3F};
u8 downloadatk_bs[] = {0x39, 0x20, 0, 0x48, 10, 0x2, 0, 0x10, 0x8C, 0x1, 0x12, 0x40, 0, 0x3F};
u8 downloadspatk_bs[] = {0x39, 0x20, 0, 0x48, 10, 0x10, 0, 0x10, 0x8D, 0x1, 0x12, 0x40, 0, 0x3F};
u8 absorb_ability_boost_bs[]= {3, 2, 0x39, 0x10, 0, 0x48, 0, 0x2, 0, 0x83, 0x8, 0, 0x10, 0x8E, 0x1, 0x12, 0x40, 0, 0x28, 0x4E, 0x8A, 0x2D, 0x08};
u8 absorb_ability_immune_bs[] = {3, 2, 0x39, 0x10, 0, 0x83, 0x9, 0, 0x10, 0x8F, 0x1, 0x12, 0x40, 0, 0x28, 0x4E, 0x8A, 0x2D, 0x08};
u8 aftermath_bs[] = {0x10, 0x92, 0x1, 0x12, 0x40, 0, 0x35, 0x80, 0x42, 0x2, 0x2, 0x0, 0x1, 0x10, 0, 0xB, 1, 0xC, 1, 0x19, 1, 0, 0, 0, 0, 0, 0x3C};
u8 pickpocket_bs[] = {0x3A, 0x10, 0x93, 0x1, 0x12, 0x40, 0, 0x83, 2, 0, 0x3A, 0x3C};
u8 mummy_bs[] = {0x3A, 0x10, 0x94, 0x1, 0x12, 0x40, 0, 0x3C};
u8 gooey_bs[] = {0x3A, 0x89, 0xC0, 0x1B, 0xB5, 0x2D, 0x08, 0x10, 0x95, 0x1, 0x12, 0x40, 0, 0x47, 0x45, 1, 1, 0x84, 0x44, 0x02, 0x02, 0x13, 0xA8, 0xC8, 0x5C, 0x08, 0x12, 0x40, 0, 0x3C};
u8 cursedbody_bs[] = {0x3A, 0x10, 0x96, 0x1, 0x12, 0x40, 0, 0x3C};
u8 rattled_bs[] = {0x3A, 0x89, 0x80, 0x1B, 0xB5, 0x2D, 0x08, 0x10, 0x95, 0x1, 0x12, 0x20, 0, 0x47, 0x45, 0, 1, 0x84, 0x44, 0x02, 0x02, 0x13, 0xA8, 0xC8, 0x5C, 0x08, 0x12, 0x40, 0, 0x3C};
u8 weakarmor_bs[] = {0x3A, 0x10, 0x95, 1, 0x12, 0x40, 0, 0x83, 3, 0, 0x83, 4, 0, 0x3C};
u8 changetargetstat_bs[] = {0x89, 0x80, 0x1B, 0xB5, 0x2D, 0x08, 0x47, 0x45, 0, 1, 0x84, 0x44, 0x02, 0x02, 0x13, 0xA8, 0xC8, 0x5C, 0x08, 0x12, 0x40, 0, 0x3C};
u8 moody_bs[] = {0x39, 0x20, 0, 0x10, 0x95, 1, 0x12, 0x40, 0, 0x83, 5, 0, 0x83, 6, 0, 0x3F};
u8 defiant_bs[] = {0x3A, 0x20, 0x95, 1, 0x12, 0x20, 0, 0x89, 0x80, 0x1B, 0xB5, 0x2D, 0x08, 0x47, 0x45, 0, 1, 0x84, 0x44, 0x02, 0x02, 0x13, 0xA8, 0xC8, 0x5C, 0x08, 0x12, 0x40, 0, 0x3C};
u8 pressure_bs[] = {0x39, 0x20, 0, 0x10, 0x98, 0x1, 0x12, 0x40, 0, 0x3F};
u8 unnerve_bs[] = {0x39, 0x20, 0, 0x83, 0xA, 0, 0x10, 0x99, 0x1, 0x12, 0x40, 0, 0x3F};
u8 aurabreak_bs[] = {0x39, 0x20, 0, 0x10, 0x9A, 0x1, 0x12, 0x40, 0, 0x3F};
u8 fairyaura_bs[] = {0x39, 0x20, 0, 0x10, 0x9B, 0x1, 0x12, 0x40, 0, 0x3F};
u8 darkaura_bs[] = {0x39, 0x20, 0, 0x10, 0x9C, 0x1, 0x12, 0x40, 0, 0x3F};
u8 itemhurt_bs[] = {0x39, 0x10, 0, 0x45, 10, 0x0F, 0, 0, 0, 0, 0x10, 0x9E, 0x1, 0x12, 0x40, 0, 0x41, 4, 0xB8, 0x2D, 0x08, 0x19, 1, 0, 0, 0, 0, 0, 0x3E};
u8 flameorb_bs[] = {0x39, 0x10, 0, 0x64, 10, 0x10, 0x9F, 0x1, 0x12, 0x35, 0, 0x98, 0xA, 0x3E};
u8 toxicorb_bs[] = {0x39, 0x10, 0, 0x64, 10, 0x10, 0xA0, 0x1, 0x12, 0x35, 0, 0x98, 0xA, 0x3E};
u8 airballon_bs[] = {0x39, 0x10, 0, 0x10, 0xA1, 0x1, 0x12, 0x40, 0, 0x3E};
u8 weaknesspolicyattack[] = {0x2E, 0x8E, 0x44, 0x02, 0x02, 0x21, 0x2E, 0x84, 0x44, 0x02, 0x02, 0x0F, 0x89, 0x1, 0x5B, 0xB8, 0x2D, 0x08, 0x2E, 0x37, 0x43, 0x02, 0x02, 0x04, 0x41, 0xD4, 0x8C, 0x2D, 0x08, 0x3C};
u8 weaknesspolicyspattack[] = {0x2E, 0x8E, 0x44, 0x02, 0x02, 0x24, 0x2E, 0x84, 0x44, 0x02, 0x02, 0x12, 0x89, 0x1, 0x5B, 0xB8, 0x2D, 0x08, 0x2E, 0x37, 0x43, 0x02, 0x02, 0x04, 0x41, 0xD4, 0x8C, 0x2D, 0x08, 0x3C};
u8 weaknesspolicy_bs[] = {0x45, 10, 7, 0, 0, 0, 0, 0x83, 12, 0, 0x6A, 10, 0x3E, 0x3E};
u8 ejectbutton_bs[] = {0x10, 0xA3, 0x1, 0x12, 0x40, 0, 0x6A, 0, 0x50, 10, 0, 0, 0, 0, 0xE2, 10, 0x3A, 0x51, 10, 0x2, 0x58, 10, 0x4C, 10, 0x4D, 10, 0x73, 10, 0x10, 3, 0, 0x4E, 10, 1, 0x3A, 0x52, 10, 0x3E};
u8 can_switch_bs[] = {0x50, 0x8A, 1, 0, 0, 0};
u8 rockyhelmet_bs[] = {0x45, 1, 0x0F, 0, 0, 0, 0, 0xB, 1, 0xC, 1, 0x10, 0xA4, 0x1, 0x12, 0x40, 0, 0x19, 1, 0, 0, 0, 0, 0, 0x3E};
u8 balloonpops_bs[] = {0x10, 0xA5, 0x1, 0x12, 0x39, 0, 0x6A, 0, 0x3E};
u8 destinyknot_bs[] = {0x65, 1, 0, 0, 0xF, 0, 0x10, 0xA3, 0x1, 0x12, 0x40, 0x0, 0x10, 0xA6, 0x1, 0x12, 0x40, 0, 0x3E};
u8 statraise_bs[] = {0x45, 10, 7, 0, 0, 0, 0, 0x89, 0x1, 0x5B, 0xB8, 0x2D, 0x08, 0x2E, 0x37, 0x43, 0x02, 0x02, 0x04, 0x41, 0xD4, 0x8C, 0x2D, 0x08, 0x6A, 0, 0x3E};
u8 mentalherb_bs[] = {0x45, 10, 7, 0, 0, 0, 0, 0x83, 13, 0, 0x6A, 10, 0x3E};
u8 disable_end_bs[] = {0x10, 0x86, 0, 0x12, 0x40, 0, 0x3C};
u8 encore_end_bs[] = {0x10, 0x88, 0, 0x12, 0x40, 0, 0x3C};
u8 healblock_end_bs[] = {0x10, 0xA7, 0, 0x12, 0x40, 0, 0x3C};
u8 magicbounce_bs[] = {0x83, 14, 0, 2, 3, 0x39, 0x20, 0, 0x10, 0xA8, 1, 0x12, 0x40, 0, 0x35, 0x80, 0x42, 0x2, 0x2, 0, 0xC, 0x80, 0, 0x76, 1, 1, 0x3C};
u8 angerpoint_bs[] = {0x3A, 0x10, 0xA9, 0x1, 0x12, 0x40, 0, 0x3C};
//not function declarations. Just used to link Battle Scripts that are implemented using ASM and BSP's format
void *frisk_bs();
void *bad_dreams_bs();

#endif /* B_SCRIPTS */
