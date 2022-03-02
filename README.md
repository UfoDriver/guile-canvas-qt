# Simple drawing canvas to use with Guile

Compile and run with

```qmake-qt5 && make && ./canvas```

Connecting to guile:

```telnet localhost 37146```

Or, better, accessing from emacs with geiser:

```M-x and connect-to-guile```

## Functions supported

`(reset)` - fully resets canvas

`(draw-point x y)` - draws point at x, y

`(draw-line x1 y1 x2 y2)` - draws line from x1, y1 to x2, y2

`(set-pen-color r g b)` - sets pen color in RGB format


Thanks to [these][1] [blog][2] [posts][3].

[1]: https://web.archive.org/web/20181208023324/https://somacomputacional.wordpress.com/2013/12/28/integrar-a-gnu-guile-con-c-parte-1/
[2]: https://web.archive.org/web/20140127180720/http://somacomputacional.wordpress.com/2013/12/28/integrar-a-gnu-guile-con-c-parte-2/
[3]: https://web.archive.org/web/20140129015306/https://somacomputacional.wordpress.com/2013/12/29/integrar-a-gnu-guile-con-c-parte-3/
