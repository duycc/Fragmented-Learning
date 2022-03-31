# -*- coding: utf-8 -*-
"""
 * @file     unittest_subtest.py
 * @brief    
 * @author   YongDu
 * @date     2022-03-31
"""
import unittest


class SubTest(unittest.TestCase):
    def test_combined(self):
        self.assertRegex('abc', 'a')
        self.assertRegex('abc', 'B')

        self.assertRegex('abc', 'c')
        self.assertRegex('abc', 'd')

    def test_with_subtest(self):
        for pat in ['a', 'B', 'c', 'd']:
            with self.subTest(pattern=pat):
                self.assertRegex('abc', pat)
