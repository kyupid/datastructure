package org.example;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.assertj.core.api.Assertions.assertThatThrownBy;

class SingleLinkedListTest {

    @Test
    @DisplayName("insertAtHead(): list 머리에 element를 담을 수 있다.")
    void insertAtHead() {
        SingleLinkedList<String> list = new SingleLinkedList<>();
        list.insertAtHead("1");
        list.insertAtHead("2");
        list.insertAtHead("3");
        list.insertAtHead("4");

        assertThat(list.size()).isEqualTo(4);
        assertThat(list.find(0)).isEqualTo("4");
        assertThat(list.find(1)).isEqualTo("3");
        assertThat(list.find(2)).isEqualTo("2");
        assertThat(list.find(3)).isEqualTo("1");
    }

    @Test
    @DisplayName("insertAtTail(): list 꼬리에 element를 담을 수 있다.")
    void insertAtTail() {
        SingleLinkedList<String> list = new SingleLinkedList<>();
        list.insertAtTail("1");
        list.insertAtTail("2");
        list.insertAtTail("3");
        list.insertAtTail("4");

        assertThat(list.size()).isEqualTo(4);
        assertThat(list.find(0)).isEqualTo("1");
        assertThat(list.find(1)).isEqualTo("2");
        assertThat(list.find(2)).isEqualTo("3");
        assertThat(list.find(3)).isEqualTo("4");
    }

    @Test
    @DisplayName("find(index): list 에서 인덱스로 노드를 찾을 수 있다.")
    void findByIndex() {
        SingleLinkedList<String> list = new SingleLinkedList<>();
        list.insertAtTail("1");
        list.insertAtTail("2");
        list.insertAtTail("3");
        list.insertAtTail("4");

        assertThat(list.find(0)).isEqualTo("1");
        assertThat(list.find(1)).isEqualTo("2");
        assertThat(list.find(2)).isEqualTo("3");
        assertThat(list.find(3)).isEqualTo("4");
        assertThatThrownBy(() -> list.find(4))
                .isInstanceOf(IndexOutOfBoundsException.class);
    }

    @Test
    @DisplayName("getIndex(): list 에서 데이터로 인덱스를 찾을 수 있다.")
    void getIndex() {
        SingleLinkedList<String> list = new SingleLinkedList<>();
        list.insertAtTail("1");
        list.insertAtTail("2");
        list.insertAtTail("3");
        list.insertAtTail("4");

        assertThat(list.getIndex("4")).isEqualTo(3);
        assertThat(list.getIndex("3")).isEqualTo(2);
        assertThat(list.getIndex("2")).isEqualTo(1);
        assertThat(list.getIndex("1")).isEqualTo(0);
    }

    @Test
    @DisplayName("delete(): list 에서 데이터를 삭제할 수 있다.")
    void delete() {
        // case1 첫번째삭제
        SingleLinkedList<String> list = new SingleLinkedList<>();
        list.insertAtTail("1");
        list.insertAtTail("2");
        list.insertAtTail("3");
        list.delete("1");

        assertThat(list.size()).isEqualTo(2);
        assertThat(list.find(0)).isEqualTo("2");
        assertThat(list.find(1)).isEqualTo("3");

        // case2 중간삭제
        SingleLinkedList<String> list2 = new SingleLinkedList<>();
        list2.insertAtTail("1");
        list2.insertAtTail("2");
        list2.insertAtTail("3");
        list2.delete("2");

        assertThat(list2.size()).isEqualTo(2);
        assertThat(list2.find(0)).isEqualTo("1");
        assertThat(list2.find(1)).isEqualTo("3");

        // case3 끝삭제
        SingleLinkedList<String> list3 = new SingleLinkedList<>();
        list3.insertAtTail("1");
        list3.insertAtTail("2");
        list3.insertAtTail("3");
        list3.delete("3");

        list3.print();

        assertThat(list3.size()).isEqualTo(2);
        assertThat(list3.find(0)).isEqualTo("1");
        assertThat(list3.find(1)).isEqualTo("2");
    }
}