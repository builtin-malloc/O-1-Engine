#ifndef DISPLAY_H
#define DISPLAY_H

/*****************************************************************************/
/*                                   TYPES                                   */
/*****************************************************************************/

struct display
{
  int dummy;
};

/*****************************************************************************/
/*                                   FRAMES                                  */
/*****************************************************************************/

void
display_begin_frame(struct display* display);
void
display_end_frame(struct display* display);

#endif /* DISPLAY_H */
