//
// Created by Usuario on 10/05/2025.
//

#include "decisionTree.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(DecisionTreeTest, InsertAndSearch) {
    DecisionTree<std::string> tree;
    tree.insertar("C");
    tree.insertar("A");
    tree.insertar("B");
    tree.insertar("D");

    EXPECT_TRUE(tree.buscar("A"));
    EXPECT_TRUE(tree.buscar("B"));
    EXPECT_TRUE(tree.buscar("C"));
    EXPECT_TRUE(tree.buscar("D"));
    EXPECT_FALSE(tree.buscar("E"));
}

TEST(DecisionTreeTest, IsEmpty) {
    DecisionTree<int> tree;
    EXPECT_TRUE(tree.estaVacio());
    tree.insertar(5);
    EXPECT_FALSE(tree.estaVacio());
}

TEST(DecisionTreeTest, DeleteNode) {
    DecisionTree<int> tree;
    tree.insertar(10);
    tree.insertar(5);
    tree.insertar(15);
    tree.eliminar(5);
    EXPECT_FALSE(tree.buscar(5));
    EXPECT_TRUE(tree.buscar(10));
    EXPECT_TRUE(tree.buscar(15));
}

TEST(DecisionTreeTest, DeleteRoot) {
    DecisionTree<int> tree;
    tree.insertar(20);
    tree.insertar(10);
    tree.insertar(30);
    tree.eliminar(20);
    EXPECT_FALSE(tree.buscar(20));
    EXPECT_TRUE(tree.buscar(10));
    EXPECT_TRUE(tree.buscar(30));
}

TEST(DecisionTreeTest, PreorderTraversal) {
    DecisionTree<std::string> tree;
    tree.insertar("M");
    tree.insertar("A");
    tree.insertar("Z");
    tree.insertar("E");

    testing::internal::CaptureStdout();
    tree.recorrerPreorden();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "M A E Z \n");
}