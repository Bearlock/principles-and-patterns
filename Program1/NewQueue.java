import java.util.*;

public class NewQueue {
    // ArrayList and LinkedList are both subclasses of List, making this simple.
    private List implementation;
    
    // Constructor accepting List type
    public NewQueue(List implementation) {
        this.implementation = implementation;
    }

    // FIFO, always add objects to the 'back'
    public void add(Object obj) {
        implementation.add(0, obj);
    }
    
    // Ternary checking if NewQueue is empty. If it is, return null, otherwise return 1st element
    public Object get() {
        Object returnObj = implementation.isEmpty() ? null : implementation.get(this.size() - 1);
        return returnObj;
    }
    
    // FIFO, always remove from the 'front'
    public void remove() {
        implementation.remove(this.size() - 1);
    }
    
    public int size() {
        return implementation.size();
    }
    
    public void clear() {
        implementation.clear();
    }
    
    // Initially clears out the passed in list
    // While-loop iterates through old implementation
    // Then it Adds elements to new implementation
    // Retains FIFO order
    public void changeImpl(List implementation) {
        implementation.clear();
        Object obj = this.get();
        while(obj != null) {
            implementation.add(0, obj);
            this.remove();
            obj = this.get();
        }
        
        // Points this list type to passed in list
        this.implementation = implementation;
    }

    public static void main(String[] args) 
    {
        System.out.println("First, an integer type\n");
        NewQueue intQueue = new NewQueue(new ArrayList());

        for(int i = 0; i < 10; i++) {
            intQueue.add(i);
        }

        System.out.println("Added 10 numbers (0-9)\n");
        printSizeAndFront(intQueue);

        for(int i = 0; i < 5; i++) {
            intQueue.remove();
        }

        System.out.println("\nRemoved 5 numbers (0-4)\n");
        printSizeAndFront(intQueue);

        //intQueue.clear();

        System.out.println("Displaying and emptying\n");
        displayAndEmptyQueue(intQueue);

        System.out.println("\nQueue emptied\n");
        printSizeAndFront(intQueue);

        for(int i = 0; i < 20; i++) {
            if(i %2 == 0) {
                intQueue.add(i);
            }
        }

        intQueue.changeImpl(new LinkedList());
        intQueue.add(11);

        System.out.println("\nAdded 10 even numbers (0-20), changed implementation and added 1 more number\n");
        printSizeAndFront(intQueue);

        intQueue.remove();
        System.out.println("\nRemoved one\n");
        printSizeAndFront(intQueue);

        intQueue.remove();
        System.out.println("\nRemoved another\n");
        printSizeAndFront(intQueue);

        System.out.println("\nNow a string type (the string is 'tenletters')\n");

        String[] tenChars = {"t","e","n","l","e","t","t","e","r","s"};
        NewQueue stringQueue = new NewQueue(new LinkedList());

        for(int i = 0; i < 10; i++) {
            stringQueue.add(tenChars[i]);
        }

        System.out.println("\nAdded 10 letters\n");
        printSizeAndFront(stringQueue);

        for(int i = 0; i < 9; i++) {
            stringQueue.remove();
        }

        System.out.println("\nRemoved 9 letters\n");
        printSizeAndFront(stringQueue);

        stringQueue.clear();

        System.out.println("\nQueue emptied\n");
        printSizeAndFront(stringQueue);

        for(String x: tenChars) {
            stringQueue.add(x);
        }

        stringQueue.changeImpl(new ArrayList());
        stringQueue.add("A");

        System.out.println("\nAdded 10 letters again, changed implementation and added 1 more letter\n");
        printSizeAndFront(stringQueue);

        stringQueue.remove();
        System.out.println("\nRemoved one\n");
        printSizeAndFront(stringQueue);

        stringQueue.remove();
        System.out.println("\nRemoved another\n");
        printSizeAndFront(stringQueue);

        System.out.println("\nDisplaying and emptying\n");
        displayAndEmptyQueue(stringQueue);

        System.out.println("\nQueue emptied\n");
        printSizeAndFront(stringQueue);

    }

    // Helper function to print stuff
    public static void printSizeAndFront(NewQueue show) {
        System.out.println("Size: " + show.size());
        System.out.println("Front: " + show.get());
    }

    public static void displayAndEmptyQueue(NewQueue show) {
        Object obj = show.get();
        while(obj != null) {
            System.out.print(obj + " ");
            show.remove();
            obj = show.get();
        }
        System.out.println("\n");
    }
}