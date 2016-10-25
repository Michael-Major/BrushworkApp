/*******************************************************************************
 * Name            : drawing_tool.cc
 * Project         : BrushWork
 * Description     : .cc file for DrawingTool class
 * Copyright	   : 2016 Andrew, Derek, Michael
 * Creation Date   : 10/10/16
 * Original Author : Andrew B., Derek G., Michael M.
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include "include/brushwork_app.h"
#include "include/pixel_buffer.h"
#include "include/drawing_tool.h"

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/

namespace image_tools {

/*******************************************************************************
 * Constructors/Destructors
 ******************************************************************************/
DrawingTool::DrawingTool(void) {
  mask_ = nullptr;
  int mask_width_ = 0;
  int mask_height_ = 0;
  int center_x_ = 0;
  int center_y_ = 0;
}


DrawingTool::~DrawingTool(void) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void DrawingTool::ApplyToCanvas
(int x, int y, PixelBuffer* display_buffer_, ColorData color) {
  // Set x and y to the coordinates of the top left pixel of mask_
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
        display_buffer_->set_pixel(x+i, y+j, (cur_canvas_col
        * (1.0 - transparency)) + (color * transparency));
    }
  }
}
}  // namespace image_tools
