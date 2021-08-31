

//interact with BookManger. By socket, pipe, etc. or, simply, by API calls.
/*
  login()
  write: 1, add newly bought book(via class Book); 2, a book is borrowed; 3, a book is replaced
  query: 1, get a list of book status; 2, certain user want to check his status
  notify: due(book)
  client起一线程不停轮询server（心跳？），server用这个轮询请求来回应有到期的书。
*/