//
//  demo.c
//  todoc_app
//
//  Created by Wesley Jesus on 08/09/24.
//

//#include <stdio.h>
//#include <gtk/gtk.h>
//
//struct Person {
//    char name[50];
//    int age;
//};
//
//// O typedef define um novo tipo chamado Customer, entao nao precisa escrever struct ao declarar a variavel.
//typedef struct {
//    char name[50];
//    int age;
//} Customer;
//
//static void
//print_hello (GtkWidget *widget,
//             gpointer   data)
//{
//  g_print ("Hello World\n");
//}
//
//static void
//activate (GtkApplication *app,
//          gpointer        user_data)
//{
//  GtkWidget *window;
//  GtkWidget *button;
//
//  window = gtk_application_window_new (app);
//  gtk_window_set_title (GTK_WINDOW (window), "Hello");
//  gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);
//
//  button = gtk_button_new_with_label ("Hello World");
//  gtk_widget_set_halign (button, GTK_ALIGN_CENTER);
//  gtk_widget_set_valign (button, GTK_ALIGN_CENTER);
//    
//  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
//  gtk_window_set_child (GTK_WINDOW (window), button);
//
//  gtk_window_present (GTK_WINDOW (window));
//}

//int
//main (int    argc,
//      char **argv)
//{
//  GtkApplication *app;
//  int status;
//
//  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
//  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
//  status = g_application_run (G_APPLICATION (app), argc, argv);
//  g_object_unref (app);
//
//  return status;
//}

//    struct Person person1;
//
//    printf("input the name: ");
//    scanf("%s", person1.name);
//
//    printf("input the age: ");
//    scanf("%d", &person1.age);
//
//    printf("\nName: %s\nAge: %d\n", person1.name, person1.age);
    
//    Customer customer = { "Wesley", 31 };
//
//    int *ptr = &customer.age;
//
//    printf("\nName: %s\nAge: %d\n", customer.name, customer.age);
//
//    printf("Endereço armazenado em ptr: %p\n", (void*)ptr);
//
//    return 0;

