# Purity

Purity is a color scheme that I am actively maintianing to fit my theming
tastes. One of the goals here is to support both light and dark themes, and to
be mostly defined with code to make updating the theme much easier.

# Supported Export Formats

* base16 (use a base16 builder)
* plain text

## Building.

This color scheme is defined entirely with code and uses the HSLuv color space.

After installing a C compiler and a copy of GNU Make, run the following:

```
make
./purity
```

All of the files related to the color scheme will be output in ./dist
