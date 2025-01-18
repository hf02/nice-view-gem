#include <zephyr/kernel.h>
#include "layer.h"
#include "../assets/custom_fonts.h"
#include <lvgl.h>

void draw_layer_status(lv_obj_t *canvas, const struct status_state *state) {
    char text[10] = {};

    if (state->layer_label == NULL) {
        sprintf(text, "Layer %i", state->layer_index);
    } else {
        strcpy(text, state->layer_label);
        to_uppercase(text);
    }

    
    switch (state->layer_index) {
        case 0:
            // dont render anything
            break;
        
        // gaming layers
        case 7:
        case 8:
        case 9:
        case 10:
            // white text with a lines on the sides
            
            // draw the left line...
            lv_draw_rect_dsc_t rect_dsc_top2;
            init_rect_dsc(&rect_dsc_top2, LVGL_FOREGROUND);
            lv_canvas_draw_rect(canvas, 0, 146 + BUFFER_OFFSET_BOTTOM, 2, 15, &rect_dsc_top2);

            // ...and the bottom line
            lv_draw_rect_dsc_t rect_dsc_bottom2;
            init_rect_dsc(&rect_dsc_bottom2, LVGL_FOREGROUND);
            lv_canvas_draw_rect(canvas, SCREEN_WIDTH - 2, 160 + BUFFER_OFFSET_BOTTOM, 1, 15, &rect_dsc_bottom2);

            // draw the text
            lv_draw_label_dsc_t label_dsc2;
            init_label_dsc(&label_dsc2, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_CENTER);
            lv_canvas_draw_text(canvas, 0, 146 + BUFFER_OFFSET_BOTTOM, 68, &label_dsc2, text);
            break;

        // everything else
        default:
            // black text on white background            

            // draw the background
            lv_draw_rect_dsc_t rect_dsc1;
            init_rect_dsc(&rect_dsc1, LVGL_FOREGROUND);
            lv_canvas_draw_rect(canvas, 0, 146 + BUFFER_OFFSET_BOTTOM, 68, 15, &rect_dsc1);

            // draw the text
            lv_draw_label_dsc_t label_dsc1;
            init_label_dsc(&label_dsc1, LVGL_BACKGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_CENTER);
            lv_canvas_draw_text(canvas, 0, 146 + BUFFER_OFFSET_BOTTOM, 68, &label_dsc1, text);
            break;
    }

}
