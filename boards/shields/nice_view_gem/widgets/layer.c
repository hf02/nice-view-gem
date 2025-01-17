#include <zephyr/kernel.h>
#include "layer.h"
#include "../assets/custom_fonts.h"
#include <lvgl.h>

void draw_layer_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_BACKGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_CENTER);

    char text[10] = {};

    if (state->layer_label == NULL) {
        sprintf(text, "Layer %i", state->layer_index);
    } else {
        strcpy(text, state->layer_label);
        to_uppercase(text);
    }

    if (state->layer_index != 0) {
        lv_draw_rect_dsc_t rect_dsc;
        init_rect_dsc(&rect_dsc, LVGL_FOREGROUND);

        lv_canvas_draw_rect(canvas, 0, 146 + BUFFER_OFFSET_BOTTOM, 68, BUFFER_OFFSET_BOTTOM + 146, &rect_dsc);
        
        lv_canvas_draw_text(canvas, 0, 146 + BUFFER_OFFSET_BOTTOM, 68, &label_dsc, text);
    }
}
