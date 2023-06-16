// gcc  -Wall -Wextra -o Ex7 Ex7.c $(pkg-config gtk+-3.0 --cflags --libs)
 #include <gtk/gtk.h>



void quitButtonClicked(__attribute__((unused)) GtkWidget *widget, 
                       __attribute__((unused)) gpointer   data)
{
    g_print("Quit Clicked\n");
    gtk_main_quit();
}


// Handle the user trying to close the window 
gboolean windowDelete(__attribute__((unused)) GtkWidget *widget, 
                      __attribute__((unused)) GdkEvent  *event,
                      __attribute__((unused)) gpointer   data)
{
    g_print("%s called.\n",__FUNCTION__);
    return TRUE;    // Returning TRUE stops the window being deleted.
                    // Returning FALSE allows deletion.   
}

int main ( int argc, char **argv) {

    GtkWidget *window;
    GtkBuilder *builder = NULL;

    gtk_init (&argc , &argv);

    builder = gtk_builder_new();

    if( gtk_builder_add_from_file (builder,"installer.glade" , NULL) == 0)
    {
        printf("gtk_builder_add_from_file FAILED\n");
        return(0);
    }

    window  = GTK_WIDGET (gtk_builder_get_object (builder,"window"));


    gtk_builder_connect_signals(builder,NULL);

    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}

