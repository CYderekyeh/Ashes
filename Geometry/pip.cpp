bool pt_in_line(P p, L line) {
    P a = p - line.pa, b = p - line.pb;
    return same((a ^ b), 0.0) && ((a * b) <= 0);
}
//can use it to check if line is entirely in polygon
//if line intersect at an edge of polygon => false
//then check midpoint(maybe more points) is in polygon
int pip(vector<P> &ps, P p) {
    int c = 0;
    for (int i = 0; i < ps.size(); ++i) {
        int a = i, b = (i + 1) % ps.size();
        L l(ps[a], ps[b]);
        P q = l.project(p);
        if ((p - q).abs() < eps && pt_in_line(q, l)) return 1;
        if (same(ps[a].y, ps[b].y) && same(ps[a].y, p.y)) continue;
        if (ps[a].y > ps[b].y) swap(a, b);
        if (ps[a].y <= p.y && p.y < ps[b].y && p.x <= ps[a].x + (ps
            [b].x - ps[a].x) / (ps[b].y - ps[a].y) * (p.y - ps[a].y))
            ++c;
    }
    return (c & 1) * 2;
}
