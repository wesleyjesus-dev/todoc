//
//  main.c
//  studyngc
//
//  Created by Wesley Jesus on 07/09/24.
//
#include <gtk/gtk.h>
#include "task_widget.c"
//#include "memory_widget.c"

long get_memory_usage_kb() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;  // Retorna o uso de memória máxima em KB
}

// Função de callback para atualizar o GtkLabel com o uso de memória
static gboolean update_memory_usage(GtkLabel *label) {
    
    long memory_usage_kb = get_memory_usage_kb();
    printf("Uso de memória: %ld KB\n", memory_usage_kb);

    double memory_usage_mb = memory_usage_kb / 1024.0;
    printf("Uso de memória: %.2f MB\n", memory_usage_mb);
    
    // Obtém o uso de memória
    long memory_usage = get_memory_usage_kb();
    
    double memory_in_mb = memory_usage / 1024.0;

    // Converte o uso de memória para string
    char memory_text[64];
    snprintf(memory_text, sizeof(memory_text), "Uso de memória: %.0f MB", memory_in_mb);

    // Atualiza o texto do GtkLabel
    gtk_label_set_text(label, memory_text);

    // Retorna TRUE para continuar chamando periodicamente
    return TRUE;
}

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

int
create_button(GtkWidget *box)
{
    GtkWidget *button;
    button = gtk_button_new_with_label ("Hello World");
    
    g_signal_connect (button,  "clicked", G_CALLBACK (print_hello), NULL);
    gtk_box_append(GTK_BOX (box), button);
}

static void
activate (GtkApplication* app,
          gpointer        user_data)
{
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *button;
    GtkWidget *label;
    
    label = gtk_label_new("Obtendo uso de memória...");

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
  
    // ####### box init #######
    gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);
    
    box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign (box, GTK_ALIGN_CENTER);
    
    
    gtk_window_set_child (GTK_WINDOW (window), box);
    // ####### box end #######
    
    // Atualiza o label a cada segundo com o uso de memória
    g_timeout_add_seconds(1, (GSourceFunc)update_memory_usage, GTK_LABEL(label));
    
    gtk_box_append(GTK_BOX (box), label);
    
    button = gtk_button_new_with_label ("Hello World");
    
    g_signal_connect (button,  "clicked", G_CALLBACK (print_hello), NULL);
    //g_signal_connect_swapped(button, "clicked", G_CALLBACK (gtk_window_destroy), window);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK (create_button), box);
    
    gtk_box_append(GTK_BOX (box), button);
    
    create_task(box);
    
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
