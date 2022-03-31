# -*- coding: utf-8 -*-
"""
 * @file     unittest_equality_container.py
 * @brief    
 * @author   YongDu
 * @date     2022-03-31
"""
import textwrap
import unittest


class ContainerEqualityTest(unittest.TestCase):
    def test_count(self):
        self.assertCountEqual(
            [1, 2, 3, 2],
            [1, 3, 2, 3],
        )

    def test_dict(self):
        self.assertDictEqual(
            {'a': 1, 'b': 2},
            {'a': 1, 'b': 3},
        )

    def test_list(self):
        self.assertListEqual(
            [1, 2, 3],
            [1, 3, 2],
        )

    def test_multilint_string(self):
        self.assertMultiLineEqual(
            textwrap.dedent(
                """
            This string
            has more than one
            line.
            """
            ),
            textwrap.dedent(
                """
            This string has
            more than two
            lines.
            """
            ),
        )

    def test_squence(self):
        self.assertSequenceEqual(
            [1, 2, 3],
            [1, 3, 2],
        )

    def test_set(self):
        self.assertSetEqual(
            set([1, 3, 2]),
            set([1, 3, 2, 4]),
        )

    def test_tuple(self):
        self.assertTupleEqual(
            (1, 'a'),
            (1, 'b'),
        )
