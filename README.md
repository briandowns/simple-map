# simple-map

simple-map is a C library that implements a simple, dynamically sized hashmap using strings for keys.  It allows for adding, updating, and deleting keys of any type.  If a map size of 0 is given, the map will be created with a default size of 16.

## Features

* Dynamic resizing - When the map grows to the point that no more entries can be made, it will dynamically increase it's size.
* Values are void pointers so you can store anything.

An example can be found in the `examples` directory.

## Test

```sh
make test
```

## Contributing

Please feel free to open a PR!

## License

simple-map source code is available under the BSD 2 clause [License](/LICENSE).

## Contact

[@bdowns328](http://twitter.com/bdowns328)
