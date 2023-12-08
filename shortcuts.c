#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

static GtkWidget *grid;
static GtkWidget *shortcut1;

void do_shortcut() {
	system("xterm -e top");
}

int main(int argc, char *argv[]) {
    // Initialize GTK
    GtkWidget *window, *grid, *shortcut1;
    gtk_init(&argc, &argv);

    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Shortcuts");
//    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Connect the "destroy" signal to the main window
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //Adding the grid and buttons
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    shortcut1 = gtk_button_new_with_label("top");
    g_signal_connect(shortcut1, "clicked", G_CALLBACK(do_shortcut), NULL);
    gtk_grid_attach(GTK_GRID(grid), shortcut1, 0, 0, 1, 1);

    // Start the GTK main loop
    gtk_widget_show_all(window);
    gtk_main();


    return 0;
}
