/*
 * Copyright (C) 2017 Jianhui Zhao <jianhuizhao329@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _LOG_H
#define _LOG_H

#include <syslog.h>
#include "common.h"

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/*
 * Use the syslog output log and include the name and number of rows at the call
 */
#define uh_log(priority, format...) __uh_log(__FILENAME__, __LINE__, priority, format)

#if (UHTTPD_DEBUG)
#define uh_log_debug(format...)     uh_log(LOG_DEBUG, format)
#else
#define uh_log_debug(format...)
#endif

#define uh_log_info(format...)      uh_log(LOG_INFO, format)
#define uh_log_err(format...)       uh_log(LOG_ERR, format)

void  __uh_log(const char *filename, int line, int priority, const char *format, ...);

#endif
