#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <gtk/gtk.h>

#include "config.h"

static GtkWidget *grid;
static GtkWidget *shortcut;
int x;
int y;

void buttonClick(GtkWidget *widget, gpointer data) {
	// Cast the data pointer to the ShortcutDef struct type
	struct shortcutDef *shortcut = (struct shortcutDef *)data;
	//system(shortcut->action);
	#ifdef __OpenBSD__
		if(pledge("stdio rpath proc exec", NULL) == -1) {
			perror("Failed to pledge");
			return;
		}
	#endif
	system(shortcut->action);
}

int main(int argc, char *argv[]) {
    // Initialize GTK
    GtkWidget *window, *grid;
    gtk_init(&argc, &argv);

    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "OtterPanel");
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //Adding the grid and buttons
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    for (int i = 0; i < sizeof(shortcutID) / sizeof(shortcutID[0]); ++i) {
	    GtkWidget *shortcut;
	    shortcut = gtk_button_new_with_label(shortcutID[i].label);
	    g_signal_connect(shortcut, "clicked", G_CALLBACK(buttonClick), &shortcutID[i].id);
	    gtk_grid_attach(GTK_GRID(grid), shortcut, x, y, 1, 1);

	    if (vertical == 0 && x != maxButtonsOnRow - 1) {
		    x++;
	    } else {
		    y++;
		    x = 0;
	    }
    }

    // Start the GTK main loop
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
