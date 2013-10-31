#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <iostream>

using namespace std;

/* This is a callback function. The data arguments are ignored
 * in this example. More on callbacks below. */

/*
static void hello( GtkWidget *widget,
                   gpointer   data )
{
    g_print ("Hello World\n");
}
 */



class cAttacker {
    gint x, y, width, height, delta;
public:
    cAttacker();
    void draw(GtkWidget *widget);
    void move(void);
    void dropBomb(void);
} oAttacker;

cAttacker::cAttacker() {

    x = 20;
    y = 50;
    width = 25;
    height = 20;
    delta = 3;
}

void cAttacker::draw(GtkWidget* widget) {

    gdk_draw_rectangle(widget->window,
            widget->style->fg_gc[gtk_widget_get_state(widget)],
            1,
            x, y, width, height);
}

void cAttacker::move() {

    if (x < 20) delta = 3;
    else if (x > 300) delta = -3;
    x = x + delta;
}

void cAttacker::dropBomb() {

    // TODO
}





class cDefender {
    gint x, y, width, height, delta;
public:
    cDefender();
    void draw(GtkWidget *widget);
    void moveLeft(void);
    void moveRight(void);
    void shoot(void);
} oDefender;

cDefender::cDefender() {

    x = 50;
    y = 200;
    width = 25;
    height = 20;
    delta = 7;
}

void cDefender::draw(GtkWidget* widget) {

    gdk_draw_rectangle(widget->window,
            widget->style->fg_gc[gtk_widget_get_state(widget)],
            1,
            x, y, width, height);
}

void cDefender::moveLeft() {
    if (x > 20) x = x - delta;
}

void cDefender::moveRight() {
    if (x < 300) x = x + delta;
}

void cDefender::shoot() {
    // TODO
}


gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data)
{
  switch (event->keyval)
  {
    case GDK_z:
        case GDK_Left:
        oDefender.moveLeft();
        break;

    case GDK_x:
        case GDK_Right:
        oDefender.moveRight();
        break;
        
            case GDK_space:
        oDefender.shoot();
        break;
        
    case GDK_p:
      printf("key pressed: %s\n", "p");
      break;
      
    case GDK_S:
    case GDK_s:
      if (event->state & GDK_SHIFT_MASK)
      {
        printf("key pressed: %s\n", "shift + s");
      }
      else if (event->state & GDK_CONTROL_MASK)
      {
        printf("key pressed: %s\n", "ctrl + s");
      }
      else
      {
        printf("key pressed: %s\n", "s");
      }
      break;
    case GDK_m:
      if (event->state & GDK_SHIFT_MASK)
      {
        printf("key pressed: %s\n", "shift + m");
      }
      else if (event->state & GDK_CONTROL_MASK)
      {
        printf("key pressed: %s\n", "ctrl + m");
      }
      else
      {
        printf("key pressed: %s\n", "m");
      }
      break;

    default:
         g_printerr("%s\n",
               gdk_keyval_name (event->keyval));
      return FALSE; 
  }

  return FALSE; 
}


//static gboolean
//on_expose_event(GtkWidget *widget,
//    GdkEventExpose *event,
//    gpointer data)
//{
//  // draw something;
//
//  return FALSE;
//}

//static gboolean
//time_handler(GtkWidget *widget) {
//    if (widget->window == NULL) return FALSE;
//
//    // re-calculate something
//
//    gtk_widget_queue_draw(widget);
//    return TRUE;
//}


static gboolean delete_event(GtkWidget *widget,
        GdkEvent *event,
        gpointer data) {
    /* If you return FALSE in the "delete_event" signal handler,
     * GTK will emit the "destroy" signal. Returning TRUE means
     * you don't want the window to be destroyed.
     * This is useful for popping up 'are you sure you want to quit?'
     * type dialogs. */

    g_print("delete event occurred\n");

    /* Change TRUE to FALSE and the main window will be destroyed with
     * a "delete_event". */

    return FALSE;
}


static gboolean time_handler(GtkWidget *widget) {
    if (widget->window == NULL) return FALSE;

    //g_print("in time_handler()... move Attacker\n");
    cout << "in time_handler()... move Attacker" << endl;

    // re-calculate something
    oAttacker.move();

    // invalidate the window area, which will emit the expose-event signal. 
    gtk_widget_queue_draw(widget);
    
    return TRUE;
}


/* Another callback */
static void destroy(GtkWidget *widget,
        gpointer data) {
    gtk_main_quit();
}


static gint button_press_event(GtkWidget *widget,
        GdkEventButton *event) {
    if (event->button == 1) {
        //g_print("button_press_event\n"); // draw_brush (widget, event->x, event->y);

        int x = ((GdkEventButton*) event)->x;
        int y = ((GdkEventButton*) event)->y;
        //char buffer[50];
        //sprintf(buffer, "button-press-event at %d,%d\n", x, y);
        //g_print (buffer);
        g_print("button-press-event at %d,%d\n", x, y);
    }
    return TRUE;
}


static gint motion_notify_event(GtkWidget *widget,
        GdkEventMotion *event) {
    //  int x, y;
    //  GdkModifierType state;
    //
    //  if (event->is_hint)
    //    gdk_window_get_pointer (event->window, &x, &y, &state);
    //  else
    //    {
    //      x = event->x;
    //      y = event->y;
    //      state = event->state;
    //    }
    //    
    //  if (state & GDK_BUTTON1_MASK )
    //    g_print("motion_notify_event\n"); //draw_brush (widget, x, y);
    //  
    return TRUE;
}


gboolean button_press_event_callback(GtkWidget *widget, GdkEventExpose *event, gpointer data) {
    //int x = (int)event->x;
    //int y = (int)event->y;

    //int x = ((GdkEventButton*)event)->x;
    //int y = ((GdkEventButton*)event)->y;

    //if (event->button == 1 && pixmap != NULL)
    //if (event.button == 1)
    //event_click_on (x, y);

    /*
            char *buffer
            buffer=malloc(50);

            sprintf(buffer, "button-press-event at %d,%d\n", x, y);

            g_print (buffer);
     */
    g_print("button_press_event_callback\n");

    return TRUE;
}


gboolean expose_event_callback(GtkWidget *widget, GdkEventExpose *event, gpointer data) {

    //cAttacker *oAttacker = new cAttacker();

    cout << "in expose_event_callback()... draw Attacker" << endl;

    oAttacker.draw(widget);
    oDefender.draw(widget);

    /*
            GdkPoint points[6];
            GtkStyle      *blankstyle;

            points[0].x = 100;
            points[0].y = 100;
            points[1].x = 10;
            points[1].y = 10;
            points[2].x = 10;
            points[2].y = 20;
            points[3].x = 10;
            points[3].y = 40;
            points[4].x = points[0].x;
            points[4].y = points[0].y;

            blankstyle = gtk_style_new ();
            blankstyle->bg_gc[GTK_STATE_NORMAL] =
                    widget->style->bg_gc[GTK_STATE_NORMAL];
            blankstyle->dark_gc[GTK_STATE_NORMAL] =
                    widget->style->bg_gc[GTK_STATE_NORMAL];
            blankstyle->light_gc[GTK_STATE_NORMAL] =
                    widget->style->bg_gc[GTK_STATE_NORMAL];
            blankstyle->black_gc =
                    widget->style->bg_gc[GTK_STATE_NORMAL];

            gtk_paint_polygon (blankstyle,
                        widget->window,
                        GTK_STATE_NORMAL,
                        GTK_SHADOW_OUT,
                        NULL,
                        widget,
                        NULL,
                        points, 5,
                        FALSE);
     */


    /*********************************************
     * Drawing Primitives
     *********************************************/

    /*
        Draws a point, using the foreground color and other attributes of the <gdk-gc>.

        drawable
            a <gdk-drawable> (a <gdk-window> or a <gdk-pixmap>).
        gc
            a <gdk-gc>.
        x
            the x coordinate of the point.
        y
            the y coordinate of the point. 
     */
    //    gdk_draw_point(widget->window,
    //            widget->style->fg_gc[gtk_widget_get_state(widget)],
    //            2, 3);


    /*
        Draws a line, using the foreground color and other attributes of the <gdk-gc>.

        drawable
            a <gdk-drawable> (a <gdk-window> or a <gdk-pixmap>).
        gc
            a <gdk-gc>.
        x1
            the x coordinate of the start point.
        y1
            the y coordinate of the start point.
        x2
            the x coordinate of the end point.
        y2
            the y coordinate of the end point. 
     */
    //    gdk_draw_line(widget->window,
    //            widget->style->fg_gc[gtk_widget_get_state(widget)],
    //            4, 17, 16, 17);
    //


    /*
        Draws a rectangular outline or filled rectangle, using the foreground color and other attributes of the <gdk-gc>.

        A rectangle drawn filled is 1 pixel smaller in both dimensions than a rectangle outlined. Calling ‘gdk_draw_rectangle (window, gc, TRUE, 0, 0, 20, 20)’ results in a filled rectangle 20 pixels wide and 20 pixels high. Calling ‘gdk_draw_rectangle (window, gc, FALSE, 0, 0, 20, 20)’ results in an outlined rectangle with corners at (0, 0), (0, 20), (20, 20), and (20, 0), which makes it 21 pixels wide and 21 pixels high.

        drawable
            a <gdk-drawable> (a <gdk-window> or a <gdk-pixmap>).
        gc
            a <gdk-gc>.
        filled
            ‘#t’ if the rectangle should be filled.
        x
            the x coordinate of the left edge of the rectangle.
        y
            the y coordinate of the top edge of the rectangle.
        width
            the width of the rectangle.
        height
            the height of the rectangle. 
     */
    //    gdk_draw_rectangle(widget->window,
    //            widget->style->fg_gc[gtk_widget_get_state(widget)],
    //            1,
    //            20, 10, 20, 5);



    /*
        Draws an arc or a filled 'pie slice'. The arc is defined by the bounding rectangle of the entire ellipse, and the start and end angles of the part of the ellipse to be drawn.

        drawable
            a <gdk-drawable> (a <gdk-window> or a <gdk-pixmap>).
        gc
            a <gdk-gc>.
        filled
            ‘#t’ if the arc should be filled, producing a 'pie slice'.
        x
            the x coordinate of the left edge of the bounding rectangle.
        y
            the y coordinate of the top edge of the bounding rectangle.
        width
            the width of the bounding rectangle.
        height
            the height of the bounding rectangle.
        angle1
            the start angle of the arc, relative to the 3 o'clock position, counter-clockwise, in 1/64ths of a degree.
        angle2
            the end angle of the arc, relative to angle1, in 1/64ths of a degree. 


     */


    GdkColor colourBlue;
    gdk_color_parse("blue", &colourBlue);

    /*
    GdkColor colourRed;
    colourRed.red = 65535;
    colourRed.green = 0;
    colourRed.blue = 0;
     */
    //
    //    GdkGC *gc;
    //    gc = gdk_gc_new(widget->window);
    //    gdk_gc_set_rgb_fg_color(gc, &colourBlue);
    //
    //    gdk_draw_arc(widget->window,
    //            gc,
    //            TRUE,
    //            60, 50, 100, 70,
    //            0, 64 * 360);
    //
    //    // widget->allocation.width, widget->allocation.height
    //
    //
    //
    //    char buffer[12];
    //    GdkFont *font;
    //    font = gtk_style_get_font(widget->style);
    //    sprintf(buffer, "Hello World!");
    //    gdk_draw_string(widget->window, font, gc, 30, 30, buffer);
    //



    return TRUE;
}

int main(int argc,
        char *argv[]) {
    /* GtkWidget is the storage type for widgets */
    GtkWidget *window;
    //GtkWidget *button;
    //GtkObject *adj1;
    //GtkLayout *layout;
    GtkWidget *drawing_area;


    /* This is called in all GTK applications. Arguments are parsed
     * from the command line and are returned to the application. */
    gtk_init(&argc, &argv);

    /* create a new window */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);



    /* g_signal_connect (G_OBJECT (window), "destroy",
                          G_CALLBACK (gtk_widget_destroy),
                                  G_OBJECT (window));
     */


    /* Sets the border width of the window. */
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);





    /* value, lower, upper, step_increment, page_increment, page_size */
    /* Note that the page_size value only makes a difference for
     * scrollbar widgets, and the highest value you'll get is actually
     * (upper - page_size). */
    //adj1 = gtk_adjustment_new (0.0, 0.0, 101.0, 0.1, 1.0, 1.0);


    /*
    layout = gtk_layout_new(GTK_ADJUSTMENT(adj1), GTK_ADJUSTMENT(adj1) );

    //gtk_layout_set_size( layout, 300, 300 );
    gtk_layout_set_size(GTK_LAYOUT(layout),1000,1000);


    gtk_container_add (GTK_CONTAINER (window), layout);
     */

    /* Creates a new button with the label "Hello World". */
    //button = gtk_button_new_with_label ("Hello World");


    /* When the button receives the "clicked" signal, it will call the
     * function hello() passing it NULL as its argument.  The hello()
     * function is defined above. */
    //    g_signal_connect (G_OBJECT (button), "clicked",
    //		      G_CALLBACK (hello), NULL);

    /* This will cause the window to be destroyed by calling
     * gtk_widget_destroy(window) when "clicked".  Again, the destroy
     * signal could come from here, or the window manager. */
    //    g_signal_connect_swapped (G_OBJECT (button), "clicked",
    //			      G_CALLBACK (gtk_widget_destroy),
    //                              G_OBJECT (window));

    /* This packs the button into the window (a gtk container). */
    //gtk_container_add (GTK_CONTAINER (window), button);


    drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, 400, 400);
    g_signal_connect(G_OBJECT(drawing_area), "expose_event",
            G_CALLBACK(expose_event_callback), NULL);


    gtk_container_add(GTK_CONTAINER(window), drawing_area);





    /* Event signals */

    /* When the window is given the "delete_event" signal (this is given
     * by the window manager, usually by the "close" option, or on the
     * titlebar), we ask it to call the delete_event () function
     * as defined above. The data passed to the callback
     * function is NULL and is ignored in the callback function. */
    g_signal_connect(G_OBJECT(window), "delete_event",
            G_CALLBACK(delete_event), NULL);

    /* Here we connect the "destroy" event to a signal handler.  
     * This event occurs when we call gtk_widget_destroy() on the window,
     * or if we return FALSE in the "delete_event" callback. */
    g_signal_connect(G_OBJECT(window), "destroy",
            G_CALLBACK(destroy), NULL);


    g_signal_connect(G_OBJECT(drawing_area), "motion_notify_event",
            G_CALLBACK(motion_notify_event), NULL);

    g_signal_connect(G_OBJECT(drawing_area), "button_press_event",
            G_CALLBACK(button_press_event), NULL);

    g_signal_connect (G_OBJECT (window), "key_press_event", 
        G_CALLBACK (on_key_press), NULL);

    gtk_widget_set_events(drawing_area, GDK_EXPOSURE_MASK
            | GDK_LEAVE_NOTIFY_MASK
            | GDK_BUTTON_PRESS_MASK
            | GDK_POINTER_MOTION_MASK
            | GDK_POINTER_MOTION_HINT_MASK);



    gtk_window_set_title(GTK_WINDOW(window), "timer");
    
    // This function registers the timer. The time_handler() function is called repeatedly at regular intervals. In our case in every second. The timer function is called until it returns FALSE. 
    g_timeout_add(800, (GSourceFunc) time_handler, (gpointer) window);
    
    // call the timer function immediately. Otherwise, there would be one sec delay. 
    time_handler(window);


    /* The final step is to display this newly created widget. */
    //gtk_widget_show (button);
    // gtk_widget_show_all(window);
    gtk_widget_show(drawing_area);

    /* and the window */
    gtk_widget_show(window);

    /* All GTK applications must have a gtk_main(). Control ends here
     * and waits for an event to occur (like a key press or
     * mouse event). */
    gtk_main();

    return 0;
}

