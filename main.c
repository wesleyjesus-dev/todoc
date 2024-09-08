//
//  main.c
//  studyngc
//
//  Created by Wesley Jesus on 07/09/24.
//
#include <gtk/gtk.h>

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
    GtkWidget *window;
    GtkWidget *box;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
  
    // define o tamanho da tela
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
    
    box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign (box, GTK_ALIGN_CENTER);
    
    gtk_window_set_child (GTK_WINDOW (window), box);
  
    // exibe a tela
    gtk_window_present (GTK_WINDOW (window));
}

int
main (int       argc,
      char    **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    
    //link a tela com o gtk_application
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    
    status = g_application_run (G_APPLICATION (app), argc, argv);
    
    // livrar os objetos da memoria
    g_object_unref (app);
    
    return status;
}
