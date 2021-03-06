
#ifndef	__TIME_H__
#define	__TIME_H__

#include "__hxcomm.h"

/*
 * Number of clock ticks per second. A clock tick is the unit by which
 * processor time is measured and is returned by 'clock'.
 */
#ifdef __GCC__
typedef long long	 __int64;
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
typedef	 long	 time_t;
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
typedef	 __int64     clock_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
typedef  __int64   __time64_t;
#endif

#define	CLOCKS_PER_SEC	((clock_t)1000)
#define	CLK_TCK		CLOCKS_PER_SEC

#ifndef _TM_DEFINED
/*
 * A structure for storing all kinds of useful information about the
 * current (or another) time.
 */
struct tm
{
	int	tm_sec;		/* Seconds: 0-59 (K&R says 0-61?) */
	int	tm_min;		/* Minutes: 0-59 */
	int	tm_hour;	/* Hours since midnight: 0-23 */
	int	tm_mday;	/* Day of the month: 1-31 */
	int	tm_mon;		/* Months *since* january: 0-11 */
	int	tm_year;	/* Years since 1900 */
	int	tm_wday;	/* Days since Sunday (0-6) */
	int	tm_yday;	/* Days since Jan. 1: 0-365 */
	int	tm_isdst;	/* +1 Daylight Savings Time, 0 No DST,
				 * -1 don't know */
};
#define _TM_DEFINED
#endif  //_TM_DEFINED.

#ifdef	__cplusplus
extern "C" {
#endif

 clock_t  	    clock (void);
 time_t  	    _time (time_t*);
 time_t  	    _difftime (time_t, time_t);
 time_t  	    _mktime (struct tm*);
 char*  		_asctime (const struct tm*);
 char*  		_ctime (const time_t*);
 struct tm*   	_gmtime (const time_t*);
 struct tm*   	_localtime (const time_t*);
 size_t  		_strftime (char*, size_t, const char*, const struct tm*);
 char*  	    _strdate(char*);
 char*  	    _strtime(char*);

 struct timeval{
	 long tv_sec;
	 long tv_usec;
 };

 struct timezone{
	 int tz_minuteswest;
	 int tz_dsttime;
 };

int gettimeofday(struct timeval* tp,struct timezone* tzp);

//timespec object.
 struct timespec{
	 long long tv_sec;
	 long long tv_nsec;
 };

#ifdef	__cplusplus
}
#endif

#endif	/* __TIME_H__ */
