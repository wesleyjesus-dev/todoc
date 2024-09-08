//
//  task_widget.c
//  todoc_app
//
//  Created by Wesley Jesus on 08/09/24.
//

#include "task_widget.h"

static void
create_task(GtkBox *external_box)
{
    GtkWidget *box;
    GtkWidget *button;
    GtkWidget *textview;
    GtkTextBuffer *buffer;
    
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    
    button = gtk_button_new_with_label("create task");
    textview = gtk_text_view_new();
    
    gtk_widget_set_size_request(textview, 300, 300);
    
    gtk_box_append(GTK_BOX (box), textview);

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
    gtk_text_buffer_set_text(buffer, "Escreva algo aqui...", -1);
    
    gtk_box_append(GTK_BOX (box), button);
    
    gtk_box_append(external_box, box);
}
