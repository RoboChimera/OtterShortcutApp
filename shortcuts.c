#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <gtk/gtk.h>

static GtkWidget *grid;
static GtkWidget *shortcut1;

void do_shortcut(int i) {
	// Handles the actual shortcut cases
	switch (i) {
		case 1:
			system("xterm -e top &");
			break;
		default:
			system("echo 'Invalid Shortcut' &");
			break;
	}
}

void button_click(GtkWidget *widget, gpointer data) {
	int *shortcut = (int *)data;
	do_shortcut(*shortcut);
}

int main(int argc, char *argv[]) {
    int shortcutID1 = 1;
    int shortcutID2 = 2;

    // Initialize GTK
    GtkWidget *window, *grid, *shortcut1;
    gtk_init(&argc, &argv);

    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Shortcuts");
    gtk_window_set_titlebar(GTK_WINDOW(window), false);
//    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Connect the "destroy" signal to the main window
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //Adding the grid and buttons
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    shortcut1 = gtk_button_new_with_label("Execute top");
    g_signal_connect(shortcut1, "clicked", G_CALLBACK(button_click), &shortcutID1);
    gtk_grid_attach(GTK_GRID(grid), shortcut1, 0, 0, 1, 1);

    shortcut1 = gtk_button_new_with_label("shortcut1");
    g_signal_connect(shortcut1, "clicked", G_CALLBACK(button_click), &shortcutID2);
    gtk_grid_attach(GTK_GRID(grid), shortcut1, 1, 0, 1, 1);
    // Start the GTK main loop
    gtk_widget_show_all(window);
    gtk_main();


    return 0;
}
