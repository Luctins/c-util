#ifndef __DEBUG_H__
#define __DEBUG_H__

/**
	-----------------------------------------------------------------------------
	SPDX License identifyer: MIT
	-----------------------------------------------------------------------------
  @author Lucas Martins Mendes
  @date 2018
  -----------------------------------------------------------------------------
  @brief debug utilities
  -----------------------------------------------------------------------------
 */

/*----- Token Manipulation macros -----*/
#define _TOKENPASTE(a,b,c) a ## b ## c
#define TOKENPASTE(a,b,c) _TOKENPASTE(a,b,c)

#define _STR(x) #x
#define STR(x) _STR(x)

/*--- Utilities ------------------------------------------*/
#define VAR_DUMP(var,fmt) LOGD(#var": "fmt, var);
#define VAR_DUMPE(var,fmt) LOGE(#var": "fmt, var);

#define ASSERT(msg, cond, then)						\
	if(!(cond)) {}                              \
	else                                        \
	{                                           \
		LOGW(msg " : at  " STR(__LINE__));      \
		then;									\
	}

#define ASSERT_A(cond, then)						\
	if(!(cond)) {}                                  \
	else                                            \
	{                                               \
		LOGW(STR(cond) " : at  " STR(__LINE__));    \
		then;										\
	}

#define ASSERT_ERROR(msg, cond, do_err)           \
	if(!(cond)) {}                              \
	else                                        \
	{                                           \
		LOGE(msg " : at " STR(__LINE__));       \
		do_err;                                 \
	}

#define ASSERT_ERROR_A(cond, do_err)             \
	if(!(cond)) {}                              \
	else                                        \
	{                                           \
		LOGE(STR(cond) " : at " STR(__LINE__)); \
		do_err;                                 \
	}

/**
  Try evaluating expression and print results.
*/
#define TRY_DO(what, expr, do_err_expr)					\
	if(!(expr)) {										\
		LOGI("%s OK", what);							\
	} else {											\
		LOGE("%s failed, : at " STR(__LINE__), what);	\
		/*LOGE(STR(cond) " : at " STR(__LINE__));*/		\
		do_err_expr;											\
	}

/**
   Validate input argument and print error message if condition is **true**
*/
#define ARG_CHECK(expr, doerr) ASSERT_ERROR("argument check fail: " STR(expr), expr, doerr)

//static generic logging functions
#if UTIL_USE_LOG /* default logging functionality -----------------------------*/

typedef enum log_level
{
	LOG_LEVEL_NONE    = 0, /*!< No output at all */
	LOG_LEVEL_ERROR   = 1, /*!< Errors only */
	LOG_LEVEL_WARN    = 2, /*!< all above + warnings */
	LOG_LEVEL_INFO    = 3, /*!< all above + general info */
	LOG_LEVEL_VERBOSE = 4, /*!< all above + extra info */
	LOG_LEVEL_DEBUG   = 5  /*!< all above + debug dumps */
} logLevel_t;

/* Handy defines to force a specific log level */
//#define LOG_LEVEL LOG_LEVEL_NONE
//#define LOG_LEVEL LOG_LEVEL_ERROR
//#define LOG_LEVEL LOG_LEVEL_WARN
//#define LOG_LEVEL LOG_LEVEL_INFO
//#define LOG_LEVEL LOG_LEVEL_VERBOSE
//#define LOG_LEVEL LOG_LEVEL_DEBUG
//#define LOG_LEVEL  5

#ifndef LOG_LEVEL
#warning [33mLog level undefined
#define LOG_LEVEL   LOG_LEVEL_NONE
#endif

#define LOG_COLOR_EN 1

#if !(defined DEBUG_OUTPUT) && !(defined DEBUG_OUTPUT_F)
#warning [33mOutput function not defined, using default
#define DEBUG_OUTPUT_F printf
#define DEBUG_OUTPUT   printf
#endif

#if LOG_COLOR_EN

#define LOG_COLOR_BLACK   "30"
#define LOG_COLOR_RED     "31"
#define LOG_COLOR_GREEN   "32"
#define LOG_COLOR_ORANGE  "33"
#define LOG_COLOR_BLUE    "34"
#define LOG_COLOR_PURPLE  "35"
#define LOG_COLOR_CYAN    "36"
#define LOG_COLOR_WHITE   "37"
#define LOG_COLOR(COLOR)  "\033[0;" COLOR "m"
#define LOG_BOLD(COLOR)   "\033[1;" COLOR "m"

#define LOG_COLOR(COLOR)  "\033[0;" COLOR "m"
#define LOG_BOLD(COLOR)   "\033[1;" COLOR "m"
#define LOG_COLOR_E() DEBUG_OUTPUT(LOG_COLOR(LOG_COLOR_RED))
#define LOG_COLOR_W() DEBUG_OUTPUT(LOG_COLOR(LOG_COLOR_ORANGE))
#define LOG_COLOR_I() DEBUG_OUTPUT(LOG_COLOR(LOG_COLOR_GREEN))
#define LOG_COLOR_V() DEBUG_OUTPUT(LOG_COLOR(LOG_COLOR_WHITE))
#define LOG_COLOR_D() DEBUG_OUTPUT(LOG_COLOR(LOG_COLOR_BLUE))
#define LOG_COLOR_RESET() DEBUG_OUTPUT("\033[0m\n")

#else

#define LOG_COLOR_E()
#define LOG_COLOR_W()
#define LOG_COLOR_I()
#define LOG_COLOR_V()
#define LOG_COLOR_D()
#define LOG_COLOR_RESET()

#endif /* LOG_COLOR_EN  */

#endif /* UTIL_USE_LOG */
#endif /* __UTIL_H__*/
