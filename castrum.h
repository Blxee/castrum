/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrum.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 07:56:44 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/16 09:48:18 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTRUM_H
#define CASTRUM_H

#include <stdio.h>

#define PRINT_TYPE(exp) \
	_Generic((exp), \
		int:			sprintf(buf + idx, "%d", (int)exp), \
		unsigned int:	sprintf(buf + idx, "%u", (unsigned int)exp), \
		long:			sprintf(buf + idx, "%ld", (long)exp), \
		unsigned long:	sprintf(buf + idx, "%lu", (unsigned long)exp), \
		char:			sprintf(buf + idx, "%c", (char)exp), \
		unsigned char:	sprintf(buf + idx, "%hhx", (unsigned char)exp), \
		void *:			sprintf(buf + idx, "%p", (void *)exp) \
	)

#define SUCCESS_MSG(func) \
	printf("%s: \x1b[42mSUCCESS\x1b[0m\n", #func);

#define FAIL_MSG(func) \
	printf("%s at line %d: \x1b[41mFAIL\x1b[0m\n", #func, __LINE__);

int g_test_failed;
char buf[1024];
unsigned long idx;

#define RUN_TEST(func) \
	g_test_failed = 0; \
	idx = 0; \
	func(); \
	if (g_test_failed) { \
		FAIL_MSG(func) \
		printf("%s", buf); \
	} else \
		SUCCESS_MSG(func)

#define ASSERT_TRUE(exp) \
	if (!exp) { \
		idx += sprintf(buf + idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #exp); \
		idx += PRINT_TYPE(exp); \
		idx += sprintf(buf + idx, " to be true!\n"); \
		g_test_failed++; \
	}


#define ASSERT_FALSE(exp) \
	if (exp) { \
		idx += sprintf(buf + idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #exp); \
		idx += PRINT_TYPE(exp); \
		idx += sprintf(buf + idx, " to be false!\n"); \
		g_test_failed++; \
	}

#define ASSERT_EQ(lhs, rhs) \
	if (lhs != rhs) { \
		idx += sprintf(buf + idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #lhs); \
		idx += PRINT_TYPE(lhs); \
		idx += sprintf(buf + idx, " to equal \x1b[1m%s\x1b[0m: ", #rhs); \
		idx += PRINT_TYPE(rhs); \
		idx += sprintf(buf + idx, "\n"); \
		g_test_failed++; \
	}

#define ASSERT_NE(lhs, rhs) \
	if (lhs == rhs) { \
		idx += sprintf(buf + idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #lhs); \
		idx += PRINT_TYPE(lhs); \
		idx += sprintf(buf + idx, " to not equal \x1b[1m%s\x1b[0m: ", #rhs); \
		idx += PRINT_TYPE(rhs); \
		idx += sprintf(buf + idx, "\n"); \
		g_test_failed++; \
	}

#define ASSERT_GT(lhs, rhs) \
	if (lhs <= rhs) { \
		idx += sprintf(buf + idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #lhs); \
		idx += PRINT_TYPE(lhs); \
		idx += sprintf(buf + idx, " to be greater than \x1b[1m%s\x1b[0m: ", #rhs); \
		idx += PRINT_TYPE(rhs); \
		idx += sprintf(buf + idx, "\n"); \
		g_test_failed++; \
	}

#define ASSERT_GE(lhs, rhs) \
	if (lhs < rhs) { \
		idx += sprintf(buf + idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #lhs); \
		idx += PRINT_TYPE(lhs); \
		idx += sprintf(buf + idx, " to be greater or equal to \x1b[1m%s\x1b[0m: ", #rhs); \
		idx += PRINT_TYPE(rhs); \
		idx += sprintf(buf + idx, "\n"); \
		g_test_failed++; \
	}

#define ASSERT_LT(lhs, rhs) \
	if (lhs >= rhs) { \
		idx += sprintf(buf + idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #lhs); \
		idx += PRINT_TYPE(lhs); \
		idx += sprintf(buf + idx, " to be less than \x1b[1m%s\x1b[0m: ", #rhs); \
		idx += PRINT_TYPE(rhs); \
		idx += sprintf(buf + idx, "\n"); \
		g_test_failed++; \
	}

#define ASSERT_LE(lhs, rhs) \
	if (lhs > rhs) { \
		idx += sprintf(buf + idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #lhs); \
		idx += PRINT_TYPE(lhs); \
		idx += sprintf(buf + idx, " to be less or equal to \x1b[1m%s\x1b[0m: ", #rhs); \
		idx += PRINT_TYPE(rhs); \
		idx += sprintf(buf + idx, "\n"); \
		g_test_failed++; \
	}

#endif
