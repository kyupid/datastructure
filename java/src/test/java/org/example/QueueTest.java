package org.example;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

public class QueueTest {

    @Test
    void test() {
        Queue<String> queue = new Queue<>();
        queue.enqueue("1");
        assertThat(queue.peek()).isEqualTo("1");
        queue.enqueue("2");
        assertThat(queue.peek()).isEqualTo("1");
        queue.enqueue("3");
        assertThat(queue.peek()).isEqualTo("1");

        assertThat(queue.size()).isEqualTo(3);
        queue.dequeue();
        assertThat(queue.peek()).isEqualTo("2");
        queue.dequeue();
        queue.dequeue();
        assertThat(queue.dequeue()).isNull();
    }
}
