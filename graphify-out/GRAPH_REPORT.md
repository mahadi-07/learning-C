# Graph Report - .  (2026-05-31)

## Corpus Check
- Corpus is ~15,635 words - fits in a single context window. You may not need a graph.

## Summary
- 178 nodes · 372 edges · 17 communities (14 shown, 3 thin omitted)
- Extraction: 80% EXTRACTED · 20% INFERRED · 0% AMBIGUOUS · INFERRED: 74 edges (avg confidence: 0.84)
- Token cost: 90,000 input · 30,133 output

## Community Hubs (Navigation)
- [[_COMMUNITY_SDS Core API (Antirez sds.ch)|SDS Core API (Antirez sds.c/h)]]
- [[_COMMUNITY_SDS Allocator & Append Path|SDS Allocator & Append Path]]
- [[_COMMUNITY_K&R Chapter 4 RPN Calculator|K&R Chapter 4 RPN Calculator]]
- [[_COMMUNITY_SDS Hidden-Header Design & Learner Bridge|SDS Hidden-Header Design & Learner Bridge]]
- [[_COMMUNITY_Chapter 1 getchar Loop & Word Counting|Chapter 1: getchar Loop & Word Counting]]
- [[_COMMUNITY_Chapter 2 Bit Manipulation|Chapter 2: Bit Manipulation]]
- [[_COMMUNITY_Chapter 23 String Charset Filters|Chapter 2/3: String Charset Filters]]
- [[_COMMUNITY_Pointers Arrays & Pass-by-Reference|Pointers: Arrays & Pass-by-Reference]]
- [[_COMMUNITY_Pointers malloc & Returning Heap Pointers|Pointers: malloc & Returning Heap Pointers]]
- [[_COMMUNITY_itoa  reverse  strlen Family|itoa / reverse / strlen Family]]
- [[_COMMUNITY_Pointer-Out-Param (get_intget_float)|Pointer-Out-Param (get_int/get_float)]]
- [[_COMMUNITY_Exercise 1.17 Long-Line Filter|Exercise 1.17: Long-Line Filter]]
- [[_COMMUNITY_Course Resources (Video + CC4E)|Course Resources (Video + CC4E)]]
- [[_COMMUNITY_Test Macros (testhelp.h)|Test Macros (testhelp.h)]]
- [[_COMMUNITY_SDS Reference Counting (planned)|SDS Reference Counting (planned)]]

## God Nodes (most connected - your core abstractions)
1. `SDS - Simple Dynamic Strings` - 33 edges
2. `sdsMakeRoomFor()` - 19 edges
3. `sdsTest()` - 19 edges
4. `sdslen()` - 19 edges
5. `sdsnewlen()` - 15 edges
6. `sdsHdrSize()` - 12 edges
7. `sdsRemoveFreeSpace()` - 11 edges
8. `sdscatlen()` - 11 edges
9. `strlen()` - 11 edges
10. `sdssetlen()` - 10 edges

## Surprising Connections (you probably didn't know these)
- `sdsnew()` --semantically_similar_to--> `main()`  [INFERRED] [semantically similar]
  opensource/sds/sds.c → pointer/pointer and dynamic memory.c
- `sdsfree()` --semantically_similar_to--> `main()`  [INFERRED] [semantically similar]
  opensource/sds/sds.c → pointer/pointer and dynamic memory.c
- `sdscat()` --semantically_similar_to--> `strlen()`  [INFERRED] [semantically similar]
  opensource/sds/sds.c → chapter-5/chapter 5.c
- `getch()` --semantically_similar_to--> `getch()`  [INFERRED] [semantically similar]
  chapter-5/chapter 5.1.c → chapter-4/chapter-4.c
- `ungetch()` --semantically_similar_to--> `ungetch()`  [INFERRED] [semantically similar]
  chapter-5/chapter 5.1.c → chapter-4/chapter-4.c

## Hyperedges (group relationships)
- **Files using the getchar()/EOF read loop pattern** — chapter_1_chapter_1_main, chapter_1_excercise_1_11_main, chapter_1_excercise_1_13_main, chapter_3_excercise_3_1_main [INFERRED 0.85]
- **Chapter 2 bit manipulation cluster** — chapter_2_excercise_2_3_main, chapter_2_excercise_2_8_main, chapter_2_excercise_2_9_main, chapter_2_excercise_2_9_print_binary [INFERRED 0.85]
- **Charset lookup table string filter functions** — chapter_2_excercise_2_4_squeeze, chapter_2_excercise_2_6_any, readme_string_charset_filter [INFERRED 0.95]
- **SDS pluggable allocator layer** — sds_sds_sds_malloc, sds_sds_sds_realloc, sds_sds_sds_free, sds_sdsalloc_s_malloc, sds_sdsalloc_s_realloc, sds_sdsalloc_s_free [EXTRACTED 1.00]
- **SDS string lifecycle API (create/duplicate/free)** — sds_sds_sdsnewlen, sds_sds_sdsnew, sds_sds_sdsempty, sds_sds_sdsdup, sds_sds_sdsfree [EXTRACTED 1.00]
- **Learner pointer/malloc exercises** — pointer_pointer_and_dynamic_memory_main, pointer_pointer_as_function_returns_add, pointer_pointer_main [INFERRED 0.85]

## Communities (17 total, 3 thin omitted)

### Community 0 - "SDS Core API (Antirez sds.c/h)"
Cohesion: 0.14
Nodes (36): main(), Binary-safe strings (length-prefixed), Redis origin / extraction history, SDS - Simple Dynamic Strings, hex_digit_to_int(), is_hex_digit(), main(), sds_free() (+28 more)

### Community 1 - "SDS Allocator & Append Path"
Cohesion: 0.14
Nodes (21): Pluggable allocator via sdsalloc.h, Preallocation: double-on-grow up to SDS_MAX_PREALLOC, Zero-copy append from syscalls (sdsMakeRoomFor + sdsIncrLen), sdsalloc(), sdsAllocSize(), sdsavail(), sdscatfmt(), sdsclear() (+13 more)

### Community 2 - "K&R Chapter 4 RPN Calculator"
Cohesion: 0.23
Nodes (12): atof(), clear_(), clear_ (stack clear), getch(), getop(), pop(), push(), reversePolish() (+4 more)

### Community 3 - "SDS Hidden-Header Design & Learner Bridge"
Cohesion: 0.22
Nodes (14): newlen (learner's sds clone stub), Call by reference via pointers, Dynamic header sizes (sdshdr5/8/16/32/64) for memory efficiency, Hidden header before pointer pattern, Backward compatibility with C string functions, typedef sds (alias of char*), sdsAllocPtr(), struct sdshdr16 (+6 more)

### Community 4 - "Chapter 1: getchar Loop & Word Counting"
Cohesion: 0.21
Nodes (8): main(), main(), Word Counting State Machine, main(), lower(), main(), Word Length Histogram, getchar EOF Loop Pattern

### Community 5 - "Chapter 2: Bit Manipulation"
Cohesion: 0.27
Nodes (9): main(), squeeze(), main(), print_binary(), bitcount(), Brian Kernighan Bitcount Trick, main(), print_binary() (+1 more)

### Community 6 - "Chapter 2/3: String Charset Filters"
Cohesion: 0.24
Nodes (8): any(), main(), squeeze (remove chars from s1 found in s2), any (first occurrence of any s2 char in s1), main(), expand(), main(), Charset Lookup Table String Filter

### Community 7 - "Pointers: Arrays & Pass-by-Reference"
Cohesion: 0.31
Nodes (9): Func1D(), Func2D(), Func3D(), increment(), main(), print(), sumOfElements(), main() (+1 more)

### Community 8 - "Pointers: malloc & Returning Heap Pointers"
Cohesion: 0.27
Nodes (8): main(), Square(), SquareOfSum(), add(), main(), printHelloWorld(), Dynamic memory (malloc/calloc/realloc/free), Returning pointer to heap-allocated memory

### Community 9 - "itoa / reverse / strlen Family"
Cohesion: 0.31
Nodes (7): itoa(), main(), print_binary(), reverse(), main(), strlen(), sdsupdatelen()

### Community 10 - "Pointer-Out-Param (get_int/get_float)"
Cohesion: 0.57
Nodes (6): get_int(), getch(), getfloat(), main(), ungetch(), Pointer as output parameter pattern

### Community 11 - "Exercise 1.17: Long-Line Filter"
Cohesion: 0.83
Nodes (3): get_line(), main(), reverse()

## Knowledge Gaps
- **7 isolated node(s):** `Word Length Histogram`, `Word Counting State Machine`, `C Programming for Everybody Video Lecture`, `CC4E Chapter 1 Reading`, `newlen (learner's sds clone stub)` (+2 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **3 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `strlen()` connect `itoa / reverse / strlen Family` to `SDS Core API (Antirez sds.c/h)`, `SDS Allocator & Append Path`, `K&R Chapter 4 RPN Calculator`, `Pointers: Arrays & Pass-by-Reference`?**
  _High betweenness centrality (0.360) - this node is a cross-community bridge._
- **Why does `ungets()` connect `K&R Chapter 4 RPN Calculator` to `itoa / reverse / strlen Family`?**
  _High betweenness centrality (0.174) - this node is a cross-community bridge._
- **Are the 2 inferred relationships involving `sdsTest()` (e.g. with `sdslen()` and `sdsavail()`) actually correct?**
  _`sdsTest()` has 2 INFERRED edges - model-reasoned connections that need verification._
- **Are the 9 inferred relationships involving `sdslen()` (e.g. with `sdscatfmt()` and `sdstrim()`) actually correct?**
  _`sdslen()` has 9 INFERRED edges - model-reasoned connections that need verification._
- **Are the 3 inferred relationships involving `sdsnewlen()` (e.g. with `newlen (learner's sds clone stub)` and `typedef sds (alias of char*)`) actually correct?**
  _`sdsnewlen()` has 3 INFERRED edges - model-reasoned connections that need verification._
- **What connects `Word Length Histogram`, `Word Counting State Machine`, `Brian Kernighan Bitcount Trick` to the rest of the system?**
  _15 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `SDS Core API (Antirez sds.c/h)` be split into smaller, more focused modules?**
  _Cohesion score 0.13900134952766532 - nodes in this community are weakly interconnected._