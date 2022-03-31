# -*- coding: utf-8 -*-
"""
 * @file     unittest_exception.py
 * @brief    
 * @author   YongDu
 * @date     2022-03-31
"""
import unittest


def raises_error(*args, **kwds):
    raise ValueError('Invalid value: ' + str(args) + str(kwds))


class ExceptionTest(unittest.TestCase):
    def test_trap_locally(self):
        try:
            raises_error('a', b='c')
        except ValueError:
            pass
        else:
            self.fail('Did not see ValueError')

    def test_assert_raises(self):
        self.assertRaises(ValueError, raises_error, 'a', b='c')
