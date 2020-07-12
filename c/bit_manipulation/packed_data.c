#include <stdio.h>
#include <stdbool.h>
// Line styles
#define SOLID 0
#define DOTTED 1
#define DASHED 2
// Primary colors
#define BLUE 4
#define GREEN 2
#define RED 1
// Mixed Colors
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char *colors[8] = {"black", "red", "green", "yellow",
                         "blue", "magenta", "cyan", "white"};
                         
struct box_properties
{
  bool opaque : 1;
  unsigned int fill_color : 3;
  unsigned int : 4;
  bool show_border : 1;
  unsigned int border_color : 3;
  unsigned int border_style : 2;
  unsigned int : 2;
};

void show_settings(const struct box_properties *pb);

int main(void)
{
  // Create and initialize box_properties structure
  struct box_properties box = {true, YELLOW, true, GREEN, DASHED};
  
  printf("Original box settings: \n");
  show_settings(&box);
  
  box.opaque = false;
  box.fill_color = WHITE;
  box.border_color = MAGENTA;
  box.border_style = SOLID;
  
  printf("\nModified box settings: \n");
  show_settings(&box);
  
  return 0;
}

void show_settings(const struct box_properties *pb)
{
  printf("Box is -> %s\n", pb -> opaque == true ? "opaque" : "transparent");
  printf("The fill color is -> %s\n", colors[pb -> fill_color]);
  printf("Border -> %s\n", pb -> show_border == true ? "shown" : "not shown");
  printf("The border color is -> %s\n", colors[pb -> border_color]);
  printf("The border style is -> ");

  switch(pb -> border_style)
  {
    case SOLID:
      printf("solid.\n");
      break;
    case DOTTED:
      printf("dotted.\n");
      break;
    case DASHED:
      printf("dashed.\n");
      break;
    default:
      printf("unknown type.\n");
  }
}