package org.example;

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

    public void insertAtTail() {

    }

    public void find() {

    }

    public void delete() {

    }

    public void print() {
        Node<T> temp = null;
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                temp = head;
            }
            if (i == 1) {
                temp = head.next;
            }
            if (i > 1) {
                temp = temp.next;
            }
            System.out.println(temp);
        }
    }

    public int size() {
        return this.size;
    }

    private static class Node<T> {
        T data;
        Node<T> next;

        public Node() {
        }

        // 찾은 data 새로운 객체로 리턴하기 위함. 리스트 불변성 유지
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
}
