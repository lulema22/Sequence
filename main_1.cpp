// #include <iostream>
// #include <locale>
// #include "ZipUnzip.h"
// // #include "MutableArray.h"
//
// template <typename T>
// void PrintSequence(const Sequence<T>*seq, const std::string& name) {
//     std::cout << name << "("<<seq->GetLength()<<"elem):";
//     for (int i=0; i<seq->GetLength(); i++) {
//         std::cout<<seq->Get(i) << " ";
//     }
//     std::cout<<std::endl;
// }
//
// template <typename T1, typename T2>
// void PrintPairSequence(const Sequence<std::pair<T1, T2>>*seq, const std::string& name) {
//     std::cout << name << "(" << seq->GetLength() << "elem): ";
//     for (int i=0; i<seq->GetLength();i++) {
//         std::pair<T1, T2> p=seq->Get(i);
//         std::cout << "(" << p.first << " "  << p.second << ")";
//     }
//     std::cout << std::endl;
// }
//
// //
//  int main() {
//     int arr1[] = {1,2,3,4};
//     int arr2[] = {10,20,30};
//
//     Sequence<int>* seq1 = new MutableArraySequence<int>(arr1,4);
//     Sequence<int>* seq2 = new MutableArraySequence<int>(arr2,3);
//     PrintSequence(seq1,"Sequence1");
//
//     PrintSequence(seq2,"Sequence2");
//
//     auto zipped = Zip<int, int>(seq1, seq2);
//     PrintPairSequence(zipped, "Zip ");
//     Sequence<int>* unzipped1 = nullptr;
//
//     Sequence<int>* unzipped2 = nullptr;
//     Unzip<int, int>(zipped, unzipped1, unzipped2);
//
//     PrintSequence(unzipped1, "Unzip 1");
//     PrintSequence(unzipped2, "Unzip 2");
//
//     delete seq1;
//     delete seq2;
//     delete zipped;
//     delete unzipped1;
//     delete unzipped2;
//
//     ///////////////////////////////////////////////////////////////
//      int arr[] = {1,2,3};
//      MutableArraySequence<int> mutableSeq(arr, 3);
//
//      std::cout<<"before Append:";
//      for (int i=0; i<mutableSeq.GetLength(); ++i) {
//          std::cout<<mutableSeq.Get(i)<<" ";
//      }
//      std::cout << "\n";
//
//
//      Sequence<int>* resultMutable = mutableSeq.Append(4);
//      std::cout<<"after Append ";
//
//      for (int i=0; i<resultMutable->GetLength(); ++i) {
//
//          std::cout<<resultMutable->Get(i)<<" ";
//
//      }
//      std::cout<<"\n";
//      int arr2_2[] = {10,20,30};
//      ImmutableArraySequence<int> immutableSeq(arr2_2, 3);
//
//      std::cout<<"Immutable orig";
//      for (int i=0; i<immutableSeq.GetLength(); ++i) {
//
//          std::cout<<immutableSeq.Get(i)<<" ";
//
//      }
//      std::cout<<"\n";
//
//      Sequence<int>* resultImmutable = immutableSeq.Append(40);
//      std::cout << "Immut after Append:";
//      for (int i=0; i<resultImmutable->GetLength(); ++i) {
//
//          std::cout<<resultImmutable->Get(i) << " ";
//
//      }
//      std::cout << "\n";
//
//      std::cout<<"Immut orig";
//      for (int i=0;i<immutableSeq.GetLength(); ++i) {
//
//          std::cout<<immutableSeq.Get(i)<<" ";
//
//      }
//      std::cout << "\n";
//
//      delete resultImmutable;
//
//
// //
// //
// //
//    return 0;
// }
//
//
//
