#include "openAlertBox.h"

bool gtk_confirm(char * question) {
    GtkWidget *infoDialog = gtk_message_dialog_new(
        NULL,
        GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, 
        GTK_MESSAGE_QUESTION ,GTK_BUTTONS_YES_NO, "%s\nNote: Confirming yes, could allow potential malicious access", question);
    gtk_window_set_title(GTK_WINDOW(infoDialog), "psandbox detected a violation!");
    gint r = gtk_dialog_run(GTK_DIALOG (infoDialog));
    gtk_widget_destroy(infoDialog);
    return r == GTK_RESPONSE_YES;
}