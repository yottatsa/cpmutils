#include <cpm.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include "types.h"

#define CPM_F_TIMEDATE 102

struct sfcb_e fsfcb;
struct stat fs;

struct sfcb_e *dir_get_entry_sfcb() {
  /* I've seen some shit in `libsrc/target/cpm/fcntl` */
  memcpy(fsfcb, fc_dirbuf + fc_dirpos * 32,
         sizeof(fsfcb.drive) + sizeof(fsfcb.name) + sizeof(fsfcb.ext));
  bdos(CPM_F_TIMEDATE, &fsfcb);
  return fsfcb;
}

struct stat *dir_get_entry_stat() {
  memcpy(fsfcb, fc_dirbuf + fc_dirpos * 32,
         sizeof(fsfcb.drive) + sizeof(fsfcb.name) + sizeof(fsfcb.ext));
  bdos(CPM_F_TIMEDATE, &fsfcb);
  fs.st_mtime = cpm_to_unix(fsfcb.timedate);
  fs.st_ctime = fs.st_atime = cpm_to_unix(fsfcb.c_timedate);
  fs.st_size = dir_get_entry_size();
  return fs;
}
