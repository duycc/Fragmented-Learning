# -*- coding: utf-8 -*-
"""
 * @file     unittest_in.py
 * @brief    
 * @author   YongDu
 * @date     2022-03-31
"""
import unittest


class ContainerMembershipTest(unittest.TestCase):
    def test_dict(self):
        self.assertIn(4, {1: 'a', 2: 'b', 3: 'c'})

    def test_list(self):
        self.assertIn(4, [1, 2, 3])

    def test_set(self):
        self.assertIn(4, set([1, 2, 3]))
