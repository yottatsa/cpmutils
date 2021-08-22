#pragma output noprotectmsdos
#pragma output nogfxglobals
#include "dos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int x, i;
  struct stat *stat;

  for (i = 1; i < argc; ++i) {
    if ((x = dir_move_first()) != 0)
      return (0);

    while (x == 0) {
      if (wcmatch(argv[i], dir_get_entry_name())) {
        if (!dir_get_entry_type()) {
          stat = dir_get_entry_stat();
          printf("M %s", asctime(localtime(&stat->st_mtime)));
          printf("  %s%07ld %s\n", asctime(localtime(&stat->st_atime)),
                 stat->st_size, dir_get_entry_name());
        }
      }
      x = dir_move_next();
    }
  }
}

/* vim: set ts=2 sw=2 tw=0 et : */
