/*******************************************************************************
 * Name            : spray_can_tool.cc
 * Project         : BrushWork
 * Description     : .cc file for SprayCanTool class
 * Copyright	   : 2016 Andrew, Derek, Michael
 * Creation Date   : 10/17/16
 * Original Author : Andrew B., Derek G., Michael M.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "include/spray_can_tool.h"
#include <cmath>

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/

namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
SprayCanTool::SprayCanTool(void) : DrawingTool() {
  apply_ = 0;
  center_x_ = 20;
  center_y_ = 20;
  mask_width_ = 41;
  mask_height_ = 41;
// initialize the mask for the spray can tool, which is a 41x41 circle
// that gets less and less intense as you get farther away from the center
// just like a real spray can would
  mask_ = new float* [mask_width_];

  float distance_ = 0.0;
  for (int i = 0; i < mask_width_; i++) {
    mask_[i] = new float[mask_height_];
    for (int j = 0; j < mask_height_; j++) {
      distance_ = sqrt(pow(j - center_x_, 2.0) + pow(i - center_y_, 2.0));
      if (distance_ >= 20.0) {
        mask_[i][j] = 0.0;
      } else {
        mask_[i][j] = 0.2 - distance_/100.0;
      }
    }
  }
}


SprayCanTool::~SprayCanTool(void) {
  }
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void SprayCanTool::ApplyToCanvas
(int x, int y, PixelBuffer* display_buffer_, ColorData color) {
  if (apply_ == 1) {
  // Set x and y to the coordinates of the top left pixel of mask_ so that we can
  // iterate through the array from top to bottom
    x -= center_x_;
    y -= center_y_;
    float transparency = 0.0;

    for (int i = 0; i < mask_height_; i++) {
      for (int j = 0; j < mask_width_; j++) {
        ColorData cur_canvas_col = display_buffer_->get_pixel(x+i, y+j);

        transparency = mask_[i][j];

        if (transparency > 0.0 && transparency < 1.0) {
          transparency = mask_[i][j]*cur_canvas_col.luminance();
        }

        display_buffer_->set_pixel(x+i, y+j,
        (cur_canvas_col * (1.0 - transparency))
        + (color * transparency));
      }
    }
    apply_ -= 1;
  } else {
    apply_ += 1;
  }
}
}  // namespace image_tools
