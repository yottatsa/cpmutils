#ifndef __TYPES_H__
#define __TYPES_H__

#define bcd_to_decimal(x) (x - 6 * (x >> 4))
#define cpm_to_unix(x)                                                         \
  (86400L * ((unsigned long)(x.date) + 2921L) +                                \
   3600L * ((unsigned long)(bcd_to_decimal(x.hours))) +                        \
   60L * ((unsigned long)(bcd_to_decimal(x.minutes))))

struct fcb_timedate {
  int date; /* Update date/time (days since January 1, 1978) */
  uint8_t hours;
  uint8_t minutes;
};
struct sfcb_e {
  uint8_t drive;   /* drive code */
  char name[8];    /* file name */
  char ext[3];     /* file type */
  uint8_t pwdmode; /* Password mode (0=no pwd): bit 7-Read, bit 6-Write, bit
                      4-Delete */
  char filler[11]; /* not used */
  struct fcb_timedate
      c_timedate; /* Create or Access date/time (depends on settings) */
  struct fcb_timedate timedate;
};

#endif
