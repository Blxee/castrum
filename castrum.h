/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castrum.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 07:56:44 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/15 18:52:44 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTRUM_H
#define CASTRUM_H

#include <stdio.h>

#define PRINT_TYPE(exp) \
	_Generic((exp), \
		int:			printf("%d", exp), \
		unsigned int:	printf("%u", exp), \
		long:			printf("%ld", exp), \
		unsigned long:	printf("%lu", exp), \
		char:			printf("%c", exp), \
		unsigned char:	printf("%hhx", exp), \
		void *:			printf("%p", exp), \
	)

#define SUCCESS_MSG \
	printf("%s: \x1b[42mSUCCESS\x1b[0m\n", __func__);

#define FAIL_MSG \
	printf("%s at line %d: \x1b[41mFAIL\x1b[0m\n", __func__, __LINE__);

#define ASSERT_TRUE(exp) \
	if (exp) \
		SUCCESS_MSG \
	else \
		FAIL_MSG \
		printf("\t-> expected "); \
		PRINT_TYPE(exp); \
		printf(" to be true!\n");

#define ASSERT_FALSE(exp) ASSERT_TRUE(!exp)

#define ASSERT_EQ(lhs, rhs, type) ASSERT_TRUE(((type)lhs == (type)rhs))

#define ASSERT_NE(lhs, rhs, type) ASSERT_FALSE((type)lhs != (type)rhs)

#define ASSERT_GT

#endif
