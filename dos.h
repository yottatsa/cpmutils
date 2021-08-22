#ifndef __DOS_H__
#define __DOS_H__

#include <cpm.h>
#include <sys/stat.h>
#include <time.h>
#include "types.h"

extern struct sfcb_e *dir_get_entry_sfcb();
extern struct stat *dir_get_entry_stat();

#endif
