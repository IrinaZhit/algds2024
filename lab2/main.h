#pragma once

#ifndef TREAP_H
#define TREAP_H

#include <stdio.h>
#include <stdlib.h>

Node* create(int key, int priority);

Node* merge(Node* a, Node* b);

Node* insert(Node* root, int key, int priority);

Node* rotateRight(Node* y);

Node* rotateLeft(Node* x);

Node* split(Node* root, int key, Node** left, Node** right);

#endif
