# Quotes and notes from "The Art of Assembly Language"

## Data Representation
### Conversion table

  **Hex		Binary**
	 0		 0000
	 1		 0001
	 2		 0010
	 3		 0011
	 4		 0100
	 5		 0101
	 6		 0110
	 7		 0111
	 8		 1000
	 9		 1001
	 A		 1010
	 B		 1011
	 C		 1100
	 D		 1101
	 E		 1110
	 F		 1111

### Sign and Zero Extension
Since two’s complement format integers have a fixed length, a small problem develops. What happens if you need to convert an eight bit two’s complement value to 16 bits?
This problem, and its converse (converting a 16 bit value to eight bits) can be accomplished via sign extension and contraction operations. Likewise, the 80x86 works with fixed
length values, even when processing unsigned binary numbers. Zero extension lets you
convert small unsigned values to larger unsigned values"
"Examples of sign extension:

8 Bits     16 Bits			32 Bits
 80h		FF80h			FFFFFF80h
 28h		0028h			00000028h
 9Ah		FF9Ah			FFFFFF9Ah
 7Fh		007Fh			0000007Fh
 –––		1020h			00001020h
 –––		8088h			FFFF8088h

To extend an unsigned byte you must zero extend the value. Zero extension is very
easy – just store a zero into the H.O. byte(s) of the smaller operand. For example, to zero
extend the value 82h to 16-bits you simply add a zero to the H.O. byte yielding 0082h.
8 Bits     16 Bits			32 Bits
 80h		0080h			00000080h
 28h		0028h			00000028h
 9Ah		009Ah			0000009Ah
 7Fh		007Fh			0000007Fh
 –––		1020h			00001020h
 –––		8088h			00008088h

Contraction might be troublesome if you want to contract a number that has a magnitude that is to great to fit into less bits.In this case you have overflow.
### Shifts and Rotates
Another set of logical operations which apply to bit strings are the shift and rotate
operations.
 In general, for binary, if you shift a value to the left n times, you multiply that value by 2^n. If you perform n right shifts, you will divide that number by 2^n, if the number is signed. Otherwise, you have to use an arithmetic shift right operation: for a 8 bits number, the 7th bit is shifted to the right -to the 6th - and its value is kepted for the 7th position.

## Boolean Algebra

Boolean algebra is a deductive mathematical system closed over the values zero and one (false and true). A binary operator “°” defined over this set of values accepts a pair of boolean inputs and produces a single boolean value. For example, the boolean AND operator accepts two boolean inputs and produces a single boolean output (the logical AND of the two inputs.
The symbol “•” represents the logical AND operation.
The symbol “+” represents the logical OR operation.
The (’) symbol denoteis logical negation (NOT).
We will also use the following set of postulates:
**P1** Boolean algebra is closed under the AND, OR, and NOT operations.
**P2** The identity element with respect to • is one and + is zero. There is no identity element with respect to logical NOT.
**P3** The • and + operators are commutative.
**P4** • and + are distributive with respect to one another. That is, A • (B + C) = (A • B) + (A • C) and A + (B • C) = (A + B) • (A + C).
**P5** For every value A there exists a value A’ such that A•A’ = 0 and A+A’ = 1. This value is the logical complement (or NOT) of A.
**P6** • and + are both associative. That is, (A•B)•C = A•(B•C) and (A+B)+C = A+(B+C).

Some theorem on boolean algebra

**Th1**: A + A = A
**Th2**: A • A = A
**Th3**: A + 0 = A
**Th4**: A • 1 = A
**Th5**: A • 0 = 0
**Th6**: A + 1 = 1
**Th7**: (A + B)’ = A’ • B’
**Th8**: (A • B)’ = A’ + B’
**Th9**: A + A•B = A
**Th10**: A •(A + B) = A
**Th11**: A + A’B = A+B
**Th12**: A’ • (A + B’) = A’B’
**Th13**: AB + AB’ = A
**Th14**: (A’+B’) • (A’ + B) = A’
**Th15**: A + A’ = 1
**Th16**: A • A’ = 0

Th7 and Th8 are DeMorgan’s Theorems.

### Correspondence Between Electronic Circuits and Boolean Functions
There is a one-to-one correspondence between an electrical circuits and boolean functions. For any boolean function you can design an electronic circuit and vice versa. Since boolean functions only require the AND, OR, and NOT boolean operators, we can construct any electronic circuit using these operations exclusively
One interesting fact is that you only need a single gate type to implement any electronic circuit.

### Combinatorial Circuits

A combinatorial circuit is a system containing basic boolean operations (AND, OR, NOT), some inputs, and a set of outputs. Since each output corresponds to an individual logic function, a combinatorial circuit often implements several different boolean functions. It is very important that you remember this fact – each output represents a different boolean function. A computer’s CPU is built up from various combinatorial circuits. See Half Adder, Full Adder and Seven Segment Display.

###  Sequential and Clocked Logic

One major problem with combinatorial logic is that it is memoryless. In theory, all logic function outputs depend only on the current inputs. Any change in the input values is immediately reflected in the outputs4. Unfortunately, computers need the ability to remember the results of past computations. This is the domain of sequential or clocked logic.A memory cell is an electronic circuit that remembers an input value after the removal of that input value. 
The most basic memory unit is the set/reset flip-flop. An improved version would be D flip-flop.You can remember a sequence of bits by combining several D flip-flops in parallel. Concatenating flip-flops to store an n-bit value forms a register. 
D flip-flops are useful for building many sequential circuits above and beyond simple registers. For example, you can build a shift register that shifts the bits one position to the left on each clock pulse.You can even build a counter, that counts the number of times the clock toggles from one to zero and back to one using flip-flops.

### Okay, What Does It Have To Do With Programming, Then?

Once you have registers, counters, and shift registers, you can build state machines. any algorithm you can implement in software you can also implement directly in hardware. This suggests that boolean logic is the basis for computation on all modern computer systems. Any program you can write, you can specify as a sequence of boolean equations.
There are times when a hardware implementation is better. A hardware solution can be one, two, three, or more orders of magnitude faster than an equivalent software solution. Therefore, some time critical operations may require a hardware solution.
A more interesting fact is that the converse of the above statement is also true. Not only can you implement all software functions in hardware, but it is also possible to implement all hardware functions in software. This is an important revelation because many operations you would normally implement in hardware are much cheaper to implement using software on a microprocessor. Indeed, this is a primary use of assembly language in modernsystems – to inexpensively replace a complex electronic circuit. It is often possible to replace many tens or hundreds of dollars of electronic components with a single $25 microcomputer chip. The whole field of *embedded systems* deals with this very problem.

## System Organization
### A bit of computer Architecure : Basic System Components

The basic operational design of a computer system is called its architecture. John Von Neumann, a pioneer in computer design, is given credit for the architecture of most computers in use today. For example, the 80x86 family uses the Von Neumann architecture (VNA). A typical Von Neumann system has three major components: the central processing unit (or CPU), memory, and input/output (or I/O).
In VNA machines, like the 80x86 family, the CPU is where all the action takes place. All computations occur inside the CPU. Data and CPU instructions reside in memory until required by the CPU. To the CPU, most I/O devices look like memory because theCPU can store data to an output device and read data from an input device. The major difference between memory and I/O locations is the fact that I/O locations are generally associated with external devices in the outside world.
The system bus connects the various components of a VNA machine. The 80x86 family has three major busses: the address bus, the data bus, and the control bus. A bus is a collection of wires on which electrical signals pass between components in the system.
The size of the *data bus* affects the performance of the system more than the size of any other bus. Indeed, having a 8 bits data bus means the processor can only access 1 byte of data per memory cycle.
The *address bus* convey addresses that enable to differentiate memory locations and I/O devices. The system designer assigns a unique memory address to each memory element and I/O device. The number of address that can be accessed through these buses is determined by thei size. A 20 bits address bus can access 1,048,576 (2^20) addresses, a 48 bits can access (2^48) 2.8147498e+14 addresses.
The *control bus* is an eclectic collection of signals that control how the processor communicates with the rest of the system. This bus will specify the direction of data flow (read/write), system clocks, interrupt lines, status lines, etc.
The *memory subsystem*. The 80x86 supports byte addressable memory. Therefore, the basic memory unit is a byte. So with 20, 24, and 32 address lines, the 80x86 processors can address one megabyte, 16 megabytes, and four gigabytes of memory, respectively.Think of memory as a linear array of bytes. The address of the first byte is zero and the address of the last byte is 2n-1.r
*The System Clock* of the CPU handles all synchronization  within a computer system. The system clock is an electrical signal on the control bus which alternates between zero and one at a periodic rate. The system clock gates many of the logic gates that make up the CPU allowing them to operate in a synchronized fashion.The frequency with which the system clock alternates between zero and one is the system clock frequency. The time it takes for the system clock to switch from zero to one and back to zero is the clock period. One full period is also called a clock cycle.Since all CPU operations are synchronized around the clock, the CPU cannot perform tasks any faster than the clock. However, just because a CPU is running at some clock frequency doesn’t mean that it is executing that many operations each second. Many operations take multiple clock cycles to complete so the CPU often performs operations at a significantly lower rate.
*Memory access* is probably the most common CPU activity. Memory access is definitely an operation synchronized around the system clock. That is, reading a value from memory or writing a value to memory occurs no more often than once every clock cycle. Indeed, on many 80x86 processors, it takes several clock cycles to access a memory location. The memory access time is the number of clock cycles the system requires to access a memory location; this is an important value since longer memory access times result in lower performance.
Several CPU components are managing internal operations of the CPU such as CPU registers, Arithmetic & Logical Unit, Bus interface Unit, Control Unit and Intruction Sets, the x86 Instruction Set...
CPU registers are very special memory locations constructed from flip-flops.
The names for the x86 registers are
AX –The accumulator register
BX –The base address register
CX –The count register
DX –The data register
The *x86 Instuction Set* : The x86 CPUs provide 20 basic instruction classes.The instructions are mov (two forms), add, sub, cmp, and, or, not, je, jne,
jb, jbe, ja, jae, jmp, brk, iret, halt, get, and put.

## Memory Layount and Access

In a 8086 intel CPU, each register specialized in a task and can belong one of these register type: "general purpose", "segment register" or miscellaneous register.

### General Purpose Registers

8 registers :
- ax: *accumulator* where most of arithmetic and logical computations take place.
- bx: *base* that is used to hold indirect addresses 
- cx: *count* counts thing
- dx: holds the overflow form certain arithmetic operations and holds I/O addresses when accessing data on the 80x86 I/O bus.
- si and di: *source index* and *destination index* may be used as pointers to indirectly access memory. These registers can be used when processing character strings.
- sp: *stack pointer*, maintains the program stack.

### Segment registers
The 8086 has four special segment registers: cs, ds, es, and ss. These stand for Code Segment, Data Segment, Extra Segment, and Stack Segment, respectively. These registers are all 16 bits wide. They deal with selecting blocks (segments) of main memory. A segment register (e.g., cs) points at the beginning of a segment in memory. Segments of memory on the 8086 can be no larger than 65,536 bytes long. This infamous “64K segment limitation” has disturbed many a programmer.
- cs: register points at the segment containing the currently executing machine
instructions.
- ds: the data segment register generally points at global variables for the program.
- es: the extra segment register is just used to gian access to segment when it is difficult or impossible to modify the other segment registers.
- ss: this segment register points at the segment containing the 8086 stack.
The *stack* is where the 8086 stores important machine state information, subroutine return addresses, procedure parameters, and local variables.

### Segments on the 80x86

Segmented addressing is a way of addressing memory in two-dimension, using an segment value and an offset value. In other words, you see memory as an array of addresses that can be access through segment:offset values. On the 80x86, the offset value is limited to 16 bits up to 32 bits. Thus, the size of the offset limits the size of the segment. With 16 bits a segment may be no longer than 64K addresses, with 32 bits its 4 gigabytes.
The actual physical memory connected to the CPU is still a linear array of bytes.There is a function that converts a segmented address (logical address) into a physical address. The conversion is multiply the segment by 16 in hexa (10h) and add the offset. Ex: 1000:1F00 => 11F00.
A problem arises when dealing with segmented addresses. You may refer to a single object in memory using several different addresses. In other words, they are several different logical addresses that refer to the same physical address.
A way to avoid this problem is by using normailzed addresses. Normalized addresses take a special form so they are all unique and does not point to the same object in memory. There are multiple ways to normalized an address, here is one: convert the segmented address to a physical address, then append a colon between the last t digit of that address. Ex: 1000:1F00 => 11F00 => 11F0:0.

### The 80x86 Addressing Modes

The 8086 provides 17 different ways to access memory.The addressing modes provided by the 8086 family include 5 different categories:
- displacement-only or direct: consists of a 16 bit constant that specifies the address of the target location. Perfect for accessing simple variables.
- base
- displacement plus base
- base plus indexed
- displacement plus base plus indexed
