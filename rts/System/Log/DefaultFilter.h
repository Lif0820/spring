/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef _LOG_DEFAULT_FILTER_H
#define _LOG_DEFAULT_FILTER_H

/**
 * A simple filter implementation for the ILog.h logging API.
 * It routes passing logging messages to the backend, and allows to set and get,
 * what is logged and what not.
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @group logging_filter_defaultFilter_control
 * @{
 */

/**
 * Sets the minimum level to log for all sections, including the default one.
 *
 * The compile-time min-level (_LOG_LEVEL_MIN) takes precedence of this one.
 * This one takes precedence over the section specific one
 * (log_filter_section_setMinLevel).
 * You may set a more restrictive min-level then a preceding instance, but
 * setting a less restrictive one has no effect.
 *
 * @see #log_filter_global_getMinLevel
 * @see #log_filter_section_setMinLevel
 */
void log_filter_global_setMinLevel(int level);

/**
 * Returns the minimum level to log.
 * @see #log_filter_global_setMinLevel
 * @see #log_filter_section_getMinLevel
 */
int log_filter_global_getMinLevel();

/**
 * Sets whether log messages for a certain section are logged or not.
 *
 * The compile-time min-level (_LOG_LEVEL_MIN) takes precedence of this one.
 * The global run-time min-level (log_filter_global_setMinLevel) takes
 * precedence over this one.
 * You may set a more restrictive min-level then a preceding instance, but
 * setting a less restrictive one has no effect.
 *
 * On release builds, the initial default section (LOG_SECTION_DEFAULT)
 * min-level is L_INFO, and L_WARNING for non-default sections.
 * On debug builds, all sections initial min-level is set to L_DEBUG.
 *
 * CAUTION: you may only use strings defined at compile-time.
 * @see #log_filter_section_getMinLevel
 */
void log_filter_section_setMinLevel(const char* section, int level);

/**
 * Returns the minimum level to log for a certain section.
 * All sections are enabled by default.
 *
 * CAUTION: you may only use strings defined at compile-time.
 * @see #log_filter_section_setMinLevel
 */
int log_filter_section_getMinLevel(const char* section);

/** @} */ // group logging_filter_defaultFilter_control

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _LOG_DEFAULT_FILTER_H

