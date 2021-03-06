#ifndef VC_CONTROL_HANDLER_H
#define VC_CONTROL_HANDLER_H

#include <vc/vc.h>
#include <vc/control/plugin.h>

typedef gpointer (*create_t)(gpointer);
typedef void (*destroy_t)(gpointer);
typedef guint32 (*reg_cmd_t)(gpointer);
typedef GHashTable* (*commands_t)(gpointer);
typedef guint32 (*run_app_t)(gpointer);
typedef void (*raise_t)(gpointer);
typedef void (*control_command_t)(gpointer);

typedef struct {
    void* lib;
    control_plugin_t* instance;
    create_t create;
    destroy_t destroy;
    reg_cmd_t reg_cmd;
    commands_t commands;
    run_app_t run_app;
    raise_t raise;
} control_handler_t;

control_handler_t* control_handler_create(gchar*);
void control_handler_destroy(gpointer);

#endif
