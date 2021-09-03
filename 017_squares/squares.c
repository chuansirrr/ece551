int maximum(int x, int y) {
  if (x > y) {
    return x;
  }
  else {
    return y;
  }
}
int judge1(int x, int y, int low, int high, int y1, int y2) {
  if (x < high && x >= low && (y == y1 || y == y2)) {
    return 1;
  }
  else {
    return 0;
  }
}

int judge2(int x, int y, int high, int y1) {
  if (x < high && (y == 0 || y == y1)) {
    return 1;
  }
  else {
    return 0;
  }
}

void squares(int size1, int x_offset, int y_offset, int size2) {
  int w =
      maximum(size1,
              (x_offset +
               size2));  //compute the max of size1 and (x_offset + size2).  Call this w

  int h =
      maximum(size1,
              (y_offset +
               size2));  //compute the max of size1 and (y_offset + size2).  Call this h

  for (int y = 0; y < h; y++) {  //count from 0 to h. Call the number you count with y

    for (int x = 0; x < w; x++) {  //count from 0 to w. Call the number you count with x

      if (judge1(x, y, x_offset, x_offset + size2, y_offset, y_offset + size2 - 1) ||
          judge1(y, x, y_offset, y_offset + size2, x_offset, x_offset + size2 - 1)) {
        printf("*");
      }
      else if (judge2(x, y, size1, size1 - 1) || judge2(y, x, size1, size1 - 1)) {
        printf("#");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }
  //check if  EITHER
  //    ((x is between x_offset  and x_offset +size2) AND
  //     y is equal to either y_offset OR y_offset + size2 - 1 )
  //  OR
  //    ((y is between y_offset and y_offset + size2) AND
  //     x is equal to either x_offset OR x_offset + size2 -1)
  // if so, print a *

  //if not,
  // check if EITHER
  //    x is less than size1 AND (y is either 0 or size1-1)
  // OR
  //    y is less than size1 AND (x is either 0 or size1-1)
  //if so, print a #

  //else print a space
  //when you finish counting x from 0 to w,
  //print a newline
}
