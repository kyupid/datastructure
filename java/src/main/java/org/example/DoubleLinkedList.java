package org.example;

import java.util.Objects;

public class DoubleLinkedList<T> {

    private Node<T> head = new Node<>(); //dummy
    private Node<T> tail = new Node<>(); //dummy

    private int size;

    public void insertAtHead(T data) {
        Node<T> newNode = new Node<>(data);
        if (head.next == null) {
            head.next = newNode;
            tail.prev = newNode;
        } else {
            newNode.next = head.next;
            head.next = newNode;
        }
        size++;
    }

    public void insertAtTail(T data) {
        Node<T> newNode = new Node<>(data);
        if (tail.prev == null) {
            head.next = newNode;
            tail.prev = newNode;
        } else {
            newNode.next = tail.prev;
            tail.prev = newNode;
        }
        size++;
    }

    public int getIndex(T data) {
        return 0;
    }

    public T find(int index) {
        return null;
    }

    public void delete(T data) {

    }

    public int size() {
        return this.size;
    }

    private static class Node<T> {
        T data;
        Node<T> next;
        Node<T> prev;

        public Node() {
        }

        public Node(T data) {
            this.data = data;
        }

        @Override
        public String toString() {
            return "data: " + data;
        }

        // find 할때 data가지고 비교하기 위함
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Node<?> node = (Node<?>) o;
            return Objects.equals(data, node.data);
        }

        // find 할때 data가지고 비교하기 위함
        @Override
        public int hashCode() {
            return Objects.hash(data);
        }
    }

    @Override
    public String toString() {
        return "DoubleLinkedList{" +
                "head=" + head.next +
                ", tail=" + tail.prev +
                ", size=" + size +
                '}';
    }
}
