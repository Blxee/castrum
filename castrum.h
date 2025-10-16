/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrum.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 07:56:44 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/16 10:05:56 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTRUM_H
#define CASTRUM_H

#include <stdio.h>

#define PRINT_TYPE(exp) \
	_Generic((exp), \
		int:			sprintf(g_msg_buf + g_buf_idx, "%d", (int)exp), \
		unsigned int:	sprintf(g_msg_buf + g_buf_idx, "%u", (unsigned int)exp), \
		long:			sprintf(g_msg_buf + g_buf_idx, "%ld", (long)exp), \
		unsigned long:	sprintf(g_msg_buf + g_buf_idx, "%lu", (unsigned long)exp), \
		char:			sprintf(g_msg_buf + g_buf_idx, "%c", (char)exp), \
		unsigned char:	sprintf(g_msg_buf + g_buf_idx, "%hhx", (unsigned char)exp), \
		void *:			sprintf(g_msg_buf + g_buf_idx, "%p", (void *)(long)exp) \
	)

#define SUCCESS_MSG(func) \
	printf("%s: \x1b[42mSUCCESS\x1b[0m\n", #func);

#define FAIL_MSG(func) \
	printf("%s at line %d: \x1b[41mFAIL\x1b[0m\n", #func, __LINE__);

int g_test_failed;
char g_msg_buf[2048];
unsigned long g_buf_idx;

#define RUN_TEST(func) \
	g_test_failed = 0; \
	g_buf_idx = 0; \
	func(); \
	if (g_test_failed) { \
		FAIL_MSG(func) \
		printf("%s", g_msg_buf); \
	} else \
		SUCCESS_MSG(func)

#define ASSERT_TRUE(exp) \
	if (!exp) { \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #exp); \
		g_buf_idx += PRINT_TYPE(exp); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, " to be true!\n"); \
		g_test_failed++; \
	}


#define ASSERT_FALSE(exp) \
	if (exp) { \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #exp); \
		g_buf_idx += PRINT_TYPE(exp); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, " to be false!\n"); \
		g_test_failed++; \
	}

#define ASSERT_EQ(lhs, rhs) \
	if (lhs != rhs) { \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #lhs); \
		g_buf_idx += PRINT_TYPE(lhs); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, " to equal \x1b[1m%s\x1b[0m: ", #rhs); \
		g_buf_idx += PRINT_TYPE(rhs); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\n"); \
		g_test_failed++; \
	}

#define ASSERT_NE(lhs, rhs) \
	if (lhs == rhs) { \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #lhs); \
		g_buf_idx += PRINT_TYPE(lhs); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, " to not equal \x1b[1m%s\x1b[0m: ", #rhs); \
		g_buf_idx += PRINT_TYPE(rhs); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\n"); \
		g_test_failed++; \
	}

#define ASSERT_GT(lhs, rhs) \
	if (lhs <= rhs) { \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #lhs); \
		g_buf_idx += PRINT_TYPE(lhs); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, " to be greater than \x1b[1m%s\x1b[0m: ", #rhs); \
		g_buf_idx += PRINT_TYPE(rhs); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\n"); \
		g_test_failed++; \
	}

#define ASSERT_GE(lhs, rhs) \
	if (lhs < rhs) { \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #lhs); \
		g_buf_idx += PRINT_TYPE(lhs); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, " to be greater or equal to \x1b[1m%s\x1b[0m: ", #rhs); \
		g_buf_idx += PRINT_TYPE(rhs); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\n"); \
		g_test_failed++; \
	}

#define ASSERT_LT(lhs, rhs) \
	if (lhs >= rhs) { \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #lhs); \
		g_buf_idx += PRINT_TYPE(lhs); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, " to be less than \x1b[1m%s\x1b[0m: ", #rhs); \
		g_buf_idx += PRINT_TYPE(rhs); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\n"); \
		g_test_failed++; \
	}

#define ASSERT_LE(lhs, rhs) \
	if (lhs > rhs) { \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\t-> expected \x1b[1m%s\x1b[0m: ", #lhs); \
		g_buf_idx += PRINT_TYPE(lhs); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, " to be less or equal to \x1b[1m%s\x1b[0m: ", #rhs); \
		g_buf_idx += PRINT_TYPE(rhs); \
		g_buf_idx += sprintf(g_msg_buf + g_buf_idx, "\n"); \
		g_test_failed++; \
	}

#define ASSERT_ARR_EQ(lhs, rhs, size) \


#endif
