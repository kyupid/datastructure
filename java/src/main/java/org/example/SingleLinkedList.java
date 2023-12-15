package org.example;

public class SingleLinkedList<T> {

    private Node<T> head;
    private int size;

    public void insertAtHead(T data) {
        // 첫번째로 넣는 노드
        if (size == 0) {
            head = new Node<>();
            head.data = data;
        } else if (size == 1) {
            Node<T> newNode = new Node<>();
            newNode.data = data;
            head.next = newNode;
        } else if (size > 1) {
            Node<T> nextNode = head.next;
            Node<T> newNode = new Node<>();
            newNode.data = data;
            head.next = newNode;
            head.next.next = nextNode;
        }
        size++;
    }

    public void insertAtTail() {

    }

    public void find() {

    }

    public void delete() {

    }

    public void print() {

    }

    public int size() {
        return this.size;
    }

    private static class Node<T> {
        T data;
        Node<T> next;

    }
}
