package org.example;

import java.util.NoSuchElementException;
import java.util.Objects;

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

    public void insertAtTail(T data) {
        if (size == 0) {
            head = new Node<>();
            head.data = data;
        } else if (size == 1) {
            Node<T> newNode = new Node<>();
            newNode.data = data;
            head.next = newNode;
        } else if (size > 1) {
            Node<T> prev = head;
            Node<T> temp = head.next;
            while (temp != null) {
                prev = temp;
                temp = temp.next;
            }
            if (prev.next != null) {
                throw new RuntimeException("prev.next must be null");
            }
            Node<T> newNode = new Node<>();
            newNode.data = data;
            prev.next = newNode;
        }
        size++;
    }

    public int getIndex(T data) {
        if (head.data == data) {
            return 0;
        }
        Node<T> temp = head.next;
        final int startIndex = 1;
        for (int i = startIndex; temp != null; i++) {
            if (temp.data == data) {
                return i;
            }
            temp = temp.next;
        }
        return -1;
    }

    public T find(int index) {
        if (index > size - 1) throw new IndexOutOfBoundsException("illegal index");
        if (index == 0) return head.data;
        if (index > 0) {
            Node<T> temp = head.next;
            final int startIndex = 1;
            for (int i = startIndex; i < size; i++) {
                if (i == index) {
                    return temp.data;
                }
                temp = temp.next;
            }
        }
        // Expected to never reach this point
        throw new IllegalStateException("The list is in an inconsistent state");
    }

    public void delete(T data) {
        if (size == 0) {
            throw new NoSuchElementException("Cannot delete from an empty list");
        }
        // case1 element가 하나인 경우
        if (head.data == data) {
            head = head.next;
            size--;
            return;
        }
        Node<T> prev = head;
        Node<T> temp = head.next;
        while (temp != null) {
            // case2 element의 맨뒤를 삭제하는 경우
            // case3 가운데 element를 삭제하는 경우
            if (temp.data == data) {
                prev.next = temp.next;
                size--;
                return;
            }
            prev = temp;
            temp = temp.next;
        }
    }

    public void print() {
        for (int i = 0; i < size; i++) {
            System.out.println(find(i));
        }
    }

    public int size() {
        return this.size;
    }

    private static class Node<T> {
        T data;
        Node<T> next;

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
}
