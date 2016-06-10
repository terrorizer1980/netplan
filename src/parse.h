#pragma once

/****************************************************
 * Parsed definitions
 ****************************************************/

typedef enum {
    ND_NONE,
    /* physical devices */
    ND_ETHERNET,
    ND_WIFI,
    /* virtual devices */
    ND_VIRTUAL,
    ND_BRIDGE = ND_VIRTUAL,
} netdef_type;

/**
 * Represent a configuration stanza
 */
typedef struct net_definition {
    netdef_type type;
    char* id;

    gboolean dhcp4;

    /* these properties are only valid for physical interfaces (type < ND_VIRTUAL) */
    char* set_name;
    struct {
        char* driver;
        char* mac;
    } match;
    gboolean wake_on_lan;
} net_definition;

/* Written/updated by parse_yaml(): char* id →  net_definition */
extern GHashTable *netdefs;

/****************************************************
 * Functions
 ****************************************************/

gboolean parse_yaml(const char* filename, GError **error);
