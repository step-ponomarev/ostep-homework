
import java.util.stream.LongStream;

public final class TlbTest {
    private static final int ADRESS_SPACE = 1024 * 1024 * 1024;
    private static final int ITERATIONS = 10000;

    public static void main(String[] args) {
        final int[] a = new int[ADRESS_SPACE];

        for (int k = 1; k < 12; k++) {
            final int PAGE_NUMBER = (int)Math.pow(2, k);
            final int PAGE_SIZE = ADRESS_SPACE / PAGE_NUMBER;
            final long[] stat = new long[ITERATIONS];

            for (int i = 0; i < ITERATIONS; i++) {
                int iterations = 0;
                long totalTime = 0;

                for (int j = 0; j < ADRESS_SPACE; j += PAGE_SIZE) {
                    final long l = System.nanoTime();
                    a[j] += 1;

                    totalTime += System.nanoTime() - l;
                    iterations++;
                }

                stat[i] = totalTime / iterations;
            }

            System.out.println("Number of pages: " + PAGE_NUMBER + '\n');
            System.out.println("Avarage: " + LongStream.of(stat).sum() / stat.length + '\n');
        }
    }
}