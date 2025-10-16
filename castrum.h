/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrum.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 07:56:44 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/16 08:56:10 by atahiri-         ###   ########.fr       */
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

#define SUCCESS_MSG \
	printf("%s: \x1b[42mSUCCESS\x1b[0m\n", __func__);

#define FAIL_MSG(func) \
	printf("%s at line %d: \x1b[41mFAIL\x1b[0m\n", #func, __LINE__);

#define ASSERT_TRUE(exp) \
	if (!exp) { \
		idx += sprintf(buf + idx, "\t-> expected "); \
		idx += PRINT_TYPE(exp); \
		idx += sprintf(buf + idx, " to be true!\n"); \
		g_test_failed++; \
	}

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
		SUCCESS_MSG

#define ASSERT_FALSE(exp) ASSERT_TRUE(!exp)

#define ASSERT_EQ(lhs, rhs, type) ASSERT_TRUE(((type)lhs == (type)rhs))

#define ASSERT_NE(lhs, rhs, type) ASSERT_FALSE((type)lhs != (type)rhs)

#define ASSERT_GT

#endif
