#ifndef LINK_H
#define LINK_H

class LinkId {
public:
  int input_id;
  int output_id;

  LinkId(int in, int out) : input_id(in), output_id(out) {}
};

class LinkGene {
public:
  LinkId link_id;
  double weight;
  bool is_enabled;

  LinkGene(LinkId id, double w, bool enabled) : link_id(id), weight(w), is_enabled(enabled) {}
};

#endif // LINK_H