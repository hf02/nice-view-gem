#include <stdlib.h>
#include <zephyr/kernel.h>
#include "animation.h"

LV_IMG_DECLARE(crystal_01);

void draw_animation(lv_obj_t *canvas) {
    return;
    lv_obj_t *art = lv_img_create(canvas);
    lv_img_set_src(art, &crystal_01);
    lv_obj_align(art, LV_ALIGN_TOP_LEFT, 0, 0);
}
