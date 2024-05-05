#include "treap.h"
#include <gtest/gtest.h>

TEST(TreapTest, Creation) {
    Node* testNode = create(14, 6);
    EXPECT_EQ(testNode->key, 14);
    EXPECT_EQ(testNode->priority, 10);
    EXPECT_EQ(testNode->left, nullptr);
    EXPECT_EQ(testNode->right, nullptr);
}

TEST(TreapTest, Insert) {
    Node* root = nullptr;
    root = insertNode(root, 14, 6);
    EXPECT_EQ(root->key, 14);
    EXPECT_EQ(root->priority, 6);
}

TEST(TreapTest, Merge) {
    Node* leftTreap = create(14, 6);
    Node* rightTreap = create(22, 8);
    TreapNode* mergedTreap = merge(leftTreap, rightTreap);
    EXPECT_EQ(mergedTreap->key, 22);
    EXPECT_EQ(mergedTreap->left->key, 14);
}

TEST(TreapTest, Split) {
    Node* root = create(20, 7);
    Node** left = create(10, 5);
    Node** right = create(30, 6);
    Node* leftSplit = split(root, 15, left, right);
    EXPECT_EQ(leftSplit->key, 10);
    EXPECT_EQ(leftSplit->left, nullptr);
    EXPECT_EQ(leftSplit->right, nullptr);
}

TEST(TreapTest, RotateLeft) {
    Node* root = create(14, 6);
    root->right = create(22, 9);
    root->left = nullptr;
    root = rotateLeft(root);
    EXPECT_EQ(root->key, 22);
    EXPECT_EQ(root->left->key, 14);
}

TEST(TreapTest, RotateRight) {
    Node* root = createNode(22, 9);
    root->left = createNode(14, 6);
    root->right = nullptr;
    root = rotateRight(root);
    EXPECT_EQ(root->key, 14);
    EXPECT_EQ(root->right->key, 22);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
